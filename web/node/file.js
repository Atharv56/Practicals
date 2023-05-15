// var http = require('http')
var fs = require('fs')

const file = fs.readFileSync('data.txt')

console.log(file.toString())

fs.writeFile('data.txt', 'This is written using js', function (err){
    if (err) throw err;
    console.log('data written to file')
});

const file1 = fs.readFileSync('data.txt')

console.log(file1.toString());
