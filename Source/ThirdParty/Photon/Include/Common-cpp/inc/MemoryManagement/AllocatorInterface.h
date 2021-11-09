/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/defines.h"

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			/**
			    Custom Allocators to be used with %Photons Memory Management need to inherit and implement this interface.
			    The allocator that is used by %Photon can be set through setAllocator(). */
			class AllocatorInterface
			{
			public:
				/**
				    Destructor. */
				virtual ~AllocatorInterface(void){}

				/**
				    This function gets called by MemoryManagement::setMaxAllocSize() and an implementation is required to behave as explained in the documentation of that function. */
				virtual void setMaxAllocSize(size_t maxAllocSize) = 0;
				
				/**
				    This function gets called by #EG_MALLOC and an implementation is required to behave as explained in the documentation of that macro. */
				virtual void* alloc(size_t size) = 0;
				
				/**
				    This function gets called by #EG_FREE and an implementation is required to behave as explained in the documentation of that macro. */
				virtual void dealloc(void* p) = 0;
				
				/**
				    This function gets called by #EG_REALLOC and an implementation is required to behave as explained in the documentation of that macro. */
				virtual void* resize(void* p, size_t size) = 0;
				
				/**
				    This function gets called by %Photon exactly once in the lifetime of the application, right before the very first allocation by Photon is made.
				    The Allocator that is returned by this function will be used for all allocations by %Photon until your code sets a different allocator through setAllocator().

				    Calling setAllocator() right in the first line of main() is already too late to guarantee that every single allocation by %Photon will use your custom allocator, because global and file-level static variables and constants (referred to here simply as
				    'globals') will be created before the program execution enters main(). If those globals are not POD-types, then they might allocate memory upon creation and in case of classes that are provided by one of the %Photon libs, such allocations will happen
				    through %Photons memory management. Hence such allocations need to already use an allocator before the program enters main().

				    The way to set an allocator that is used for allocations by such globals, is to replace the default implementation of this function by your own implementation.
				    This works in the same way like replacing the platforms default implementations of the global new and delete operators with your own implementations: %Photon provides a default implementation of this function that gets used when you don't provide your
				    own implementation, but when you do provide your own implementation, then the linker silently drops %Photons weak-linked default implementation and replaces %Photons call to it by a call to your implementation.

					Usage example:
				    @code
					class Allocator : public ExitGames::Common::MemoryManagement::AllocatorInterface
					{
					public:
						Allocator(void)
						{
						}

						virtual ~Allocator(void)
						{
						}

						virtual void setMaxAllocSize(size_t maxAllocSize)
						{
						}

						virtual void* alloc(size_t size)
						{
							return malloc(size);
						}

						virtual void dealloc(void* p)
						{
							free(p);
						}

						virtual void* resize(void* p, size_t size)
						{
							return realloc(p, size);
						}
					private:
						static void* operator new(size_t);
						static void* operator new[](size_t);
					};

					namespace ExitGames
					{
						namespace Common
						{
							namespace MemoryManagement
							{
								AllocatorInterface* AllocatorInterface::get(void)
								{
									// attention:
									// The returned pointer must already point to a valid instance at the point at which it is returned, which due to the static initialization order fiasco is not necessarily the case for a global variable.
									// A dynamically allocated variable however will leak, as there is no way to deallocate it, because it needs to stay valid until after the last global or file level static object that uses it has been destructed and due to the static initialization order fiasco there is no way to ensure that that deallocation happens after all those destructions.
									// The solution is to return the address of a function-level static variable. 
									static Allocator allocator;
									return &allocator;
								}
							}
						}
					}
				    @endcode
				    As you can can see, that example implementation of a primitive custom allocator makes operator new private.
				    The reason for this is that once it had been set through setAllocator() an allocator MUST stay valid until you can guarantee that all memory that was given out by it, has been returned to it.
				    Deleting an once used allocator prematurely, even after a different allocator has been set as the current allocator, is undefined behavior and will most likely lead to an access violation crash.
				    A static local variable of AllocatorInterface::get() is guaranteed by the C++ standard to be constructed before that function returns and hence it is also guaranteed by the standard to get destructed after everything that uses that allocator.

				    If however you want to manage the lifetime of an allocator instance dynamically through new and delete, then you need to keep track if some of its memory might still be in use, before you can safely delete such an allocator.
				    A simple approach to do this is reference counting:
				    @code
					class ReferenceCountedAllocator : public ExitGames::Common::MemoryManagement::AllocatorInterface
					{
					public:
						ReferenceCountedAllocator(void)
							: mRefCount(0)
						{
							retain();
						}

						ReferenceCountedAllocator* ReferenceCountedAllocator::retain(void)
						{
							std::lock_guard<std::mutex> lock(mMutex);
							++mRefCount;
							return this;
						}

						void ReferenceCountedAllocator::release(void)
						{
							std::unique_lock<std::mutex> lock(mMutex);
							if(!--mRefCount)
							{
								lock.unlock();
								delete this;
							}
						}

						virtual void setMaxAllocSize(size_t maxAllocSize)
						{
						}

						virtual void* alloc(size_t size)
						{
							if(!size)
								return NULL;
							retain();
							return malloc(size);
						}

						virtual void dealloc(void* p)
						{
							if(!p)
								return;
							free(p);
							release();
						}

						virtual void* resize(void* p, size_t size)
						{
							return realloc(p, size);
						}
					private:
						virtual ~ReferenceCountedAllocator(void)
						{
						}

						long long mRefCount;
						std::mutex mMutex;
					};
				    @endcode
				    @code
					void foo(void)
					{
						ReferenceCountedAllocator* pAllocator = new ReferenceCountedAllocator;
						ExitGames::Common::MemoryManagement::setAllocator(*pAllocator);
						ExitGames::Common::JString string = L"samplestring";
						ExitGames::Common::MemoryManagement::setAllocatorToDefault();
						pAllocator->release();
						// some more code
					} // only at this point, when the local JString variable 'string' gets out of scope and hence destructed, it hands its memory back to the allocator and pAllocators reference count reaches 0 so that it gets deleted
				    @endcode
				    Note that ReferenceCountedAllocator makes its destructor private to ensure that it only ever gets called by release(). A side-effect of this is that one can't return it in AllocatorInterface::get() (at least without leaking it).
				    So there are usage scenarios for the approaches of both example custom allocators: use the approach of class Allocator for a custom allocator that should be returned by AllocatorInterface::get(), and use the approach of ReferenceCountedAllocator for a
				    custom allocator that should be able to have a limited lifetime.

					Furthermore note that your custom allocator must be thread-safe (which would not be the case for ReferenceCountedAllocator, if it would not protect mRefCount with a lock), as Photon might access it from multiple threads at once.

					Finally if for some reason you don't want any allocations on the heap to happen while global and file level static variables are getting constructed, remember that it is completely up to you where the memory that you provide to %Photon is coming from
					and how it's managed and that you can provide different allocators at different times. Hence the allocator that you return by AllocatorInterface::get() could look like this:
					@code
					class Allocator : public ExitGames::Common::MemoryManagement::AllocatorInterface
					{
					public:
						Allocator(void)
							: mCountBytes(0)
						{
						}

						virtual ~Allocator(void)
						{
						}

						virtual void setMaxAllocSize(size_t maxAllocSize)
						{
						}

						virtual void* alloc(size_t size)
						{
							static const size_t MEM_SIZE = 16*1024;
							static byte memory[MEM_SIZE];
							mCountBytes += size;
							if(mCountBytes > MEM_SIZE)
								assert(false);
							return memory+mCountBytes-size;
						}

						virtual void dealloc(void* p)
						{
						}

						virtual void* resize(void* p, size_t size)
						{
							assert(false);
							return NULL;
						}
					private:
						static void* operator new(size_t);
						static void* operator new[](size_t);

						unsigned long long mCountBytes;
					};
				    @endcode
					This variant simply allocates the memory on a static byte-array and does not reuse any memory that is returned to it (which is perfectly fine for memory that gets allocated in the constructor and deallocated in the destructor of a variable which has the
					same lifetime as the executable).

					Note that you need to make sure that the array on which the memory is allocated is big enough to cover all requests that occur until you set a different allocator. As the required amount might change when changes in your code happen or when you update to
					a new %Photon version, the assert() in alloc is important to avoid hard to track down crashes in unrelated code.

					Be aware that this primitive variant that does not reuse any memory only makes sense when you set a different allocator through setAllocator() as early as possible because the longer you wait the bigger the static array will need to be to serve all
					requests without running out of memory.
				    */
				static AllocatorInterface* get(void);
			};
			/** @file */
		}
	}
}