#!/bin/bash
#Starts monitoring SFTP users.

cd /home/abaan/AutoEmailScripts

/home/abaan/AutoEmailScripts/Calendar/Monitor.sh &
/home/abaan/AutoEmailScripts/Don/Monitor.sh &
/home/abaan/AutoEmailScripts/Robert/Monitor.sh
