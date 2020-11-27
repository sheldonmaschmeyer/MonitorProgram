#!/bin/bash
# This program will monitor a folder (specified in the variable MonitorFolder) and notify Dad that the folder's contents have changed.
# This program is the property of Skyboard Development Inc.

#The name of the user to be monitored
varUserName=Unknown

#The folder being monitored
  varMonitorFolder=/home/Calendar
#The subject of the email to be sent
  varSubjectEmail="The $varUserName SFTP folder has been Accessed and/or Modified "
#The body of the email to be sent
  varBodyEmail="$varUserName SFTP folder modified "
#The location of the AccessDetails.txt file or folder for attachment to email
  varAccessDetailsLocal="file:///home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt"

function funPlayAudio # Play audio file to notify user away from computer that an email needs sending and that the folder has been accessed.
{
  aplay /home/abaan/AutoEmailScripts/HalError.wav
}

function funSendEmail # Send an email to Dad to notify him that the Access and Modified dates of the files have changed
{
  thunderbird -compose to="bmaschmeyer@gmail.com",subject=$varSubjectEmail $(date) " +/- 15 min",body="$varUserName SFTP folder modified " $(date) " +/- 15 min.",attachment=$varAccessDetailsLocal
}

function funMasterLog #Add to the Master log file
{
  echo "" >> /home/abaan/AutoEmailScripts/ActivityLog.txt
  echo "" >> /home/abaan/AutoEmailScripts/ActivityLog.txt
  echo "Sorted by Time Access" >> /home/abaan/AutoEmailScripts/ActivityLog.txt
  echo "" >> /home/abaan/AutoEmailScripts/ActivityLog.txt

  # Directory listing by Date Accessed 
  ls $varMonitorFolder -l -h --time=atime >> /home/abaan/AutoEmailScripts/ActivityLog.txt

  echo "" >> /home/abaan/AutoEmailScripts/ActivityLog.txt
  echo "Sorted by Time Modified" >> /home/abaan/AutoEmailScripts/ActivityLog.txt
  echo "" >> /home/abaan/AutoEmailScripts/ActivityLog.txt

  # Directory listing by Date Modified
  ls $varMonitorFolder -l -h -t >> /home/abaan/AutoEmailScripts/ActivityLog.txt
}

# Repeat (Loop) this code an infinite amount of times
while [ 1 ]; do
  # Pause the code for 900 seconds
  sleep 900

  # Append (>) the file CompareDetails.txt and add (>>) the following lines
  echo "Sorted by Time Access" > /home/abaan/AutoEmailScripts/$varUserName/CompareDetails.txt
  echo "" >> /home/abaan/AutoEmailScripts/$varUserName/CompareDetails.txt

  # Directory listing by Date Accessed 
  ls $varMonitorFolder -l -h --time=atime >> /home/abaan/AutoEmailScripts/$varUserName/CompareDetails.txt

  echo "" >> /home/abaan/AutoEmailScripts/$varUserName/CompareDetails.txt
  echo "Sorted by Time Modified" >> /home/abaan/AutoEmailScripts/$varUserName/CompareDetails.txt
  echo "" >> /home/abaan/AutoEmailScripts/$varUserName/CompareDetails.txt

  # Directory listing by Date Modified
  ls $varMonitorFolder -l -h -t >> /home/abaan/AutoEmailScripts/$varUserName/CompareDetails.txt

  # AccessDetails.txt vs. CompareDetails.txt
  diff --brief /home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt /home/abaan/AutoEmailScripts/$varUserName/CompareDetails.txt > /dev/null  
    
    # If their contents are not the same then
    if [[ $? -eq 1 ]];then 
      
      # Make AccessDetails.txt the same as CompareDetails.txt 
      echo "Sorted by Time Access" > /home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt
      echo "" >> /home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt

      ls $varMonitorFolder -l -h --time=atime >> /home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt

      echo "" >> /home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt
      echo "Sorted by Time Modified" >> /home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt
      echo "" >> /home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt

      ls $varMonitorFolder -l -h -t >> /home/abaan/AutoEmailScripts/$varUserName/AccessDetails.txt

      #Call functions that play audio, send email and append the ActivityLog
      funPlayAudio &
      funSendEmail &
      funMasterLog

    fi # End If statement
 
done # End of loop
