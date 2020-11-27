#!/bin/bash
#This program adds and removes users from the list of users being monitored.
#This program is the property of Skyboard Development Inc.

#Monitors an existing user
function funExistsUser
{
  #Display instructons to user
  echo ""
  echo "Please enter the Username (i.e. don) that you want to monitor."

  #Display UserName field to user
  echo UserName:

  #Create variable and store user input for UserName
  read varUserName

  #If the user already exists in the file MonitorAll, do not add the user to the list as it will be a duplicate
  #However, if the user is not in the file MonitorAll, start monitor the user
  grep -w "$varUserName" MonitorAll.sh >/dev/null
  if [ $? -eq 0 ]
  then
	  echo "The user is already being monitored"
	  echo "Please press any key to exit the program"
	  read varExit
  else
	  #Changes all occurances of #AND to & inorder to allow the shell scripts to run simultaniously
	  sed -i 's/#AND/\&/g' MonitorAll.sh

	  #If a user was previously removed, remove placeholder file 'RemovedUser' from MonitorAll
	  sed "/RemovedUser.sh/d" MonitorAll.sh > tmp
		mv tmp MonitorAll.sh

	  #Add new user to the MonitorAll.sh file
	  echo "/home/abaan/AutoEmailScripts/$varUserName/Monitor.sh #AND" >> MonitorAll.sh

	  #Make directory
	  mkdir /home/abaan/AutoEmailScripts/$varUserName

	  #copy directory contents of MakeNewUser to newly created user to be monitored directory

	  cp -r /home/abaan/AutoEmailScripts/MakeNewUser/* /home/abaan/AutoEmailScripts/$varUserName

	  #change the contents of the varUserName in the Monitor.sh program file to monitor the new user
	  sed "s/varUserName=.*/varUserName=$varUserName/g" /home/abaan/AutoEmailScripts/$varUserName/Monitor.sh > tmp
		mv tmp /home/abaan/AutoEmailScripts/$varUserName/Monitor.sh

	  echo ""
	  echo "$varUserName has been added to the list of users being monitored."
	  echo "Please restart the computer for the changes to take effect."
	  echo "Press any key to exit"

	  read varExit
	  echo "exited"
  fi
}

#Stops monitoring a user
function funStoppingMonitoring
{
  #Display UserName field to user
  echo ""
  echo "Username of user to stop monitoring:"

  #Create variable and store user input
  read varUserName

  #If the user is in the MonitorAll File, stop monitoring the user
  #However, if the user is not in the MonitorAll File, to prevent an ugly error message,
  #notify the user and exit the program.
  grep -w "$varUserName" MonitorAll.sh >/dev/null
  if [ $? -eq 0 ]
    then
	  #Remove user from MonitorAll
	  sed "/$varUserName/d" MonitorAll.sh > tmp
		mv tmp MonitorAll.sh

	  #Workaround for not being able to remove & sign
	  echo "/home/abaan/AutoEmailScripts/RemovedUser.sh" >> MonitorAll.sh

	  #Remove directory
	  rm -rf /home/abaan/AutoEmailScripts/$varUserName

	  echo ""
	  echo "$varUserName is nolonger being monitored."
	  echo ""
	  echo "Please restart the computer for the changes to take effect."
	  echo "Press any key to exit"

	  read varExit
	  echo "exited"
    else
    	  echo "The user is already not being monitored!"
	  echo "Please press any key to exit the program"
	  read varExit
  fi
}

#Starts YaST and the Users and Group Management Module then loads the funNewMonitoring function
function funCreateUser
{
  echo ""
  echo "Do you want to manually create a new user or" 
  echo "automatically create a new user?"  
  while [ 1 ]; do
	read -p "[press m for manual or a for automatic]" ma
	case $ma in
	[Mm]* ) funManualUser; break;;
	[Aa]* ) funAutoUser; break;;
	* ) echo "Please answer 'm' or 'a' ";;
	esac
  done
}

#Autmatically create a new user with the correct group and permissions
function funAutoUser
{
  echo ""
  echo "Please enter the user's Full Name: "
  read varFullName
  echo ""
  echo "Please enter the user's User Name: "
  read varUserName
  
  varValidPassword="NO"
  while [ 1 ]; do
    echo ""
    echo "Please enter the password for the new user: "
    read -s varPassword
    echo ""
    echo "Please re-enter the same password for verification: "
    read -s varVerifyPassword
    case $varPassword in
      $varVerifyPassword)
        echo ""
        echo "Please enter the Root (Administrative) password"
	su root -c "useradd -g sftponly -G sftponly -p $varPassword -d /home/$varUserName -c '$varFullName' -m $varUserName
		chown $varUserName:users /home/$varUserName
		chmod 550 /home/$varUserName
		chown $varUserName:users /home/$varUserName/Documents
		chmod 770 /home/$varUserName/Documents"

        echo ""
        echo "The user $varUserName was created"
	echo "belongs to the sftponly group and"
        echo "$varUserName Home folder permissions are set to" 
        echo "read/write for the owner ($varUserName),"
        echo "the 'users' group and is not accessable by any other user"
        varValidPassword="YES"; break;;
      * )
        echo "" 
        echo "The passwords do not match!";;
      esac
  done

  echo "Automatically move all files and folders except"
  echo "Documents to a folder called '.extras' that is not"
  while [ 1 ]; do
	read -p " accessable by any user except root? [yes or no] " yn
	case $yn in
	[Yy]* ) 
	  sed "s/varUserName=.*/varUserName=$varUserName/g" /home/abaan/AutoEmailScripts/MoveFilesFoldersToExtra.sh > tmp
		mv tmp /home/abaan/AutoEmailScripts/MoveFilesFoldersToExtra.sh
	  sh MoveFilesFoldersToExtra.sh
	  ls /home/$varUserName -l
	  echo "Above is a list of files and folders in /home/$varUserName."
          echo "If their are any folders other than Documents and"
	  echo ".extras, please notify Sheldon."
	  funNewMonitoring; break;;
	[Nn]* ) funNewMonitoring; break;;
	* ) echo "Please answer yes or no. ";;
	esac
  done 
}

function funManualUser
{
  echo "Please enter Root (Administrative) password" 
  su root -c "YaST users --gtk"
  funNewMonitoring
}

function funNewMonitoring
{
  echo ""
  #Ask the user if he wants to monitor a new user
  while [ 1 ]; do
	read -p "Do you want to monitor the new user? [yes or no] " yn
	case $yn in
	[Yy]* ) funExistsUser; break;;
	[Nn]* ) echo ""
                 echo "please press any key to exit"
                 read varExit; 
                 exit;;
	* ) echo "Please answer yes or no. ";;
	esac
  done
}

#Stops monitoring a user by asking a question
function funStopMonitoring
{
  echo ""
  #Ask the user if he wants to monitor a new user
  while [ 1 ]; do
	read -p "Do you want to stop monitoring a user? [yes or no] " yn
	case $yn in
	[Yy]* ) funStoppingMonitoring; break;;
	[Nn]* ) exit;;
	* ) echo "Please answer yes or no. ";;
	esac
  done
}

#Starts YaST USer and Group Management for the purpose of Deleting or Disabling a user
function funUserDeleteDisable
{
  su root -c "YaST users --gtk"
  funStoppingMonitoring
}

function funUserRemove
{
  echo ""
  echo "WARNING: Stopping monitoring a user without either deleting or"
  echo "disabling user login will mean that the user can still login into"
  echo "the sftp therefore I strongly recommend that the user be deleted or"
  echo "disabled using the YaST - User and Group Management Module"
  echo ""
  while [ 1 ]; do
	read -p "Do you want to delete or disable a user BEFORE stopping monitoring [yes or no] " yn
	case $yn in
	[Yy]* ) funUserDeleteDisable; break;;
	[Nn]* ) funStopMonitoring; break;;
	* ) echo "Please answer yes or no. ";;
	esac
  done

}

#Asks the user if they want to monitor a new user or stop monitor a user
echo "Type 'c' or 'Create' then 'enter' to create & monitor a new user"
echo "Type 'e' or 'Exists' then 'enter' to start monitoring an existing user" 
echo "Type 'r' or 'Remove' then 'enter' to delete, disable, &/or stop monitoring user"
while [ 1 ]; do
	read -p "Press 'Esc' then 'enter' to exit the program " cerx
	case $cerx in
	[Cc]* ) funCreateUser; break;;
	[Ee]* ) funExistsUser; break;;	
	[Rr]* ) funUserRemove; break;;
        [^[]* ) exit;;
	* ) echo "Please type 'c', 'e', 'r', or press 'Esc' then 'Enter'. ";;
	esac
done
