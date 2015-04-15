/**
 * Script permettant de calculer le nombre d'occurences des lettres
 * et de les classer de la plus présente à la plus rare
 */

var fs = require('fs');

var stats = {};
var order = [];
var total = 0;

fs.readFile('./dataset/dictionary.txt', 'utf8', function (err,data) {
  if (err) {
    return console.log(err);
  }
  for (var i = 0; i < data.length; i++) {
    if (data[i] != '\n') {
      total++;
      if (stats[data[i]] == undefined)
        stats[data[i]] = 0;
      stats[data[i]]++
    }
  }
  for (var letter in stats) {
    order.push({nbr : stats[letter], letter : letter});
  }
  var i = 0;
  while (i + 1 < order.length) {
    if (order[i].nbr < order[i + 1].nbr) {
      var tmp = order[i];
      order[i] = order[i + 1];
      order[i + 1] = tmp;
      i = 0;
    }
    else
      i++;
  }
  for (var i = 0; i < order.length; i++) {
    order[i].order = i + 1;
  };
  console.log(order);
});
