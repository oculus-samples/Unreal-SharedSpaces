Go to the [Epic Developer Website](https://dev.epicgames.com/en-US) and click **Dev Portal**. Log in or create an account.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/twofactor.png" align="middle" width="450"></div>
<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/acount2fa.png" align="middle" width="450"></div>

If you haven't set up Two-Factor Authentication, click **Account Management**. Use a phone number or email to enable 2FA. When done, click *I've Enabled 2FA*.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/createorg.png" align="middle" width="450"></div>

Enter your organization name and select your country. Then click **Continue**.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/createproduct.png" align="middle" width="450"></div>
<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/createproduct2.png" align="middle" width="450"></div>

Click **Create Product**. Enter a product name, click **Continue**, and optionally upload a cover image.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/productsettings.png" align="middle" width="450"></div>

Click the gear icon (settings) next to your product name.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/productsettings2.png" align="middle" width="450"></div>
<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/agreements.png" align="middle" width="250"></div>

Click **Clients**, then **Review & accept**.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/agreements2.png" align="middle" width="450"></div>

Scroll to the bottom to enable the **Accept** button, then click it.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/agreements3.png" align="middle" width="450"></div>

Click **Clients** again, go to the Anti-Cheat Servers and Epic Account Serves licenses and accept them.
When finished click on Dashboard, go back to your product settings and click **Clients** again.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/clients.png" align="middle" width="450"></div>

Click *Add New Client*.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/clients2.png" align="middle" width="350"></div>

Enter a client name, then click *Add New Client Policy*.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/clientpolicy.png" align="middle" width="350"></div>
<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/clientpolicytype.png" align="middle" width="350"></div>

The client policy controls what the client can do with the online service. Enter a policy name and select a policy type or create a custom one.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/custompolicy.png" align="middle" width="350"></div>

If you choose *Create a Custom Policy*, click **User Required** to require a logged-in user for actions. For shared spaces to work, select **Lobbies** and check all actions. When finished, click *Add New Client Policy*, then *Add New Client*.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/productsettingsupdate.png" align="middle" width="450"></div>

Return to Product Settings. You should see a client ID and client secret.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/EAS.png" align="middle" width="450"></div>
<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/linkedclient.png" align="middle" width="450"></div>

Go to **Epic Account Services**, click **Linked Clients**, select your client, and save changes. Then go to **Permissions** and save changes.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/productsettingsupdate2.png" align="middle" width="450"></div>

Return to Product Settings. You should now see an Application ID.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/EOSPlugins.png" align="middle" width="450"></div>

Launch the Sharedspaces project. Generate Visual Studio project files and open the solution. Build and run the project. In the editor, go to **Edit > Plugins**. Search for EOS and ensure all EOS-related plugins are enabled. Restart the editor.

<div style="text-align: center; padding: 10pt;"><img src="./Media/EOS_Config/UnrealProjectSettings.png" align="middle" width="650"></div>

Go to **Edit > Project Settings > Plugins > OnlineSubsystem EOS**. Enter a Default Artifact Name. Click the **+** next to Artifacts and paste the Default Artifact Name into Artifact Name. On the EOS developer website, copy and paste the respective IDs into the Artifacts fields. For the Encryption Key, enter 64 hexadecimal characters.
