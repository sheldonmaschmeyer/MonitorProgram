#!/bin/bash
#Moves all files and folders except Documents to .extras and only root user can access .extras
varUserName=testuser
echo "Please enter the root 'Administrative' password"
su root -c "mkdir /home/$varUserName/.extras
mv /home/$varUserName/bin /home/$varUserName/.extras
mv /home/$varUserName/public_html /home/$varUserName/.extras
mv /home/$varUserName/.fonts /home/$varUserName/.extras
mv /home/$varUserName/.mozilla /home/$varUserName/.extras
mv /home/$varUserName/.bash_history /home/$varUserName/.extras
mv /home/$varUserName/.bashrc /home/$varUserName/.extras
mv /home/$varUserName/.emacs /home/$varUserName/.extras
mv /home/$varUserName/.inputrc /home/$varUserName/.extras
mv /home/$varUserName/.muttrc /home/$varUserName/.extras
mv /home/$varUserName/.profile /home/$varUserName/.extras
mv /home/$varUserName/.vimrc /home/$varUserName/.extras
mv /home/$varUserName/.xim.template /home/$varUserName/.extras
mv /home/$varUserName/.xinitrc.template /home/$varUserName/.extras
chown root:root /home/$varUserName/.extras
chmod 770 /home/$varUserName/.extras"
