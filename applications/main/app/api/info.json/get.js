module.exports = function(client, callback) {
  'use strict';

  var mathLib = require(process.cwd() +
    '/applications/main/app/api/info.json/build/Release/addon');

  if (!('n' in client.query)) {
    client.context.data = {
      err: 'Значение числа не было передано в запросе'
    };
    
    callback();
    return;
  }

  var n = +client.query.n;
  
  if (n % 1 != 0 ||
      n % 2 == 0 ||
      n < 9 ||
      n > 1e9) {
        
    client.context.data = {
      err: 'Введите корректное значение числа'
    };
    
    callback();
    return;
  }

  client.context.data = mathLib.factorize(n);
  client.context.data.uptime_sec =  impress.sandbox.process.uptime();
  callback();  
};
