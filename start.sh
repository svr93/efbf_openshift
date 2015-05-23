iptables -I INPUT -p tcp --dport 80 -m state --state NEW -j ACCEPT

cp -f cpp_code/cpp_code/factorization.h \
      applications/main/app/api/info.json/factorization.h

cp -f cpp_code/cpp_code/factorization.cpp \
      applications/main/app/api/info.json/factorization.cc

mainPath=$(pwd)
cd applications/main/app/api/info.json
. build.sh
cd $mainPath
#psql -U postgres -f fill_db.sql
node server.js
