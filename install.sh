cd docs
./composer.phar install
cd vendor/phpmyadmin/phpmyadmin
../../../composer.phar install
cd ../../../
cp ./phpMyAdmin/config.inc.php vendor/phpmyadmin/phpmyadmin/config.inc.php
