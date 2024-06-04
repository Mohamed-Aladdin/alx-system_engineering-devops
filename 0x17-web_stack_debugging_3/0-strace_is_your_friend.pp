# A puppet manuscript to replace a line in a file on a server

exec { '/usr/bin/env sed -i "s/phpp/php/g" /var/www/html/wp-settings.php': }
