# Monitor Program
There are two versions of this program.

Version 1 (2009):
This was created for my father's small business, before I started my first degree at Carleton Unviersity in Integrated Science. Earlier I was using an FTP server, a feature included with a network hard drive. This worked well and I was complimented on it (used before Dropbox existed). However, I became more cognisent of the need for security, which was not a priority at the time. I had setup a home SFTP server using my mother's computer running OpenSuse linux.  Since SFTP does not log activity, this program monitors folders accessible by others (using private/public key pairs and a password). It will send an audio notification when files and folders were changed as well as an email to my father's email account (password nolonger used). It worked wonderfully. Then I migrated it to Ubuntu linux. Some of the admin setup had to be changed since OpenSuse uses unique OS administration. It mostly worked, it continued to monitor files and folders for changes and send an email. As Dropbox evolved and became more security oriented, my father, employees, potential clients and I started to use DropBox instead. Also, I was nolonger at home, in Ottawa at Carleton U, to maintain the SFTP server. 

Version 2 (2017): 
This was done with a partner for an Operating Systems course. It translated the Version 1 montioring aspects of the program from a Bash terminal program to a C Kernal program. Other features was added by partner to organize files in the directorires that were being monitored. It was not designed as an SFTP monitor since it was not a networking course (inspired by it) as the course requirements were different. It was designed to monitor different users on a computer and sort their files and folders. If a parent wanted to monitor the user folder the child had access to, get an email notification of the files and folders that was added/changed. Sorting files and folders helps the child organize.
