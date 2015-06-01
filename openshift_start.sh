sed -i "s/0\.0\.0\.0/$OPENSHIFT_NODEJS_IP/g" config/servers.js
sed -i "s/80\,/8080 ,/g" config/servers.js
node server.js
