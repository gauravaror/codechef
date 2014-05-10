var tls = require('tls');
var fs = require('fs');

var options = {
  key: fs.readFileSync('key.pem'),
  cert: fs.readFileSync('key-cert.pem')
};

var server = tls.createServer(options, function(cleartextStream) {
  console.log('server connected',
              cleartextStream.authorized ? 'authorized' : 'unauthorized');
   var path = 'video.mp4';
  var stat = fs.statSync(path);
  var total = stat.size;
fs.createReadStream(path).pipe(cleartextStream);
/*cleartextStream.write("welcome!\n");
  cleartextStream.setEncoding('utf8');
  cleartextStream.pipe(cleartextStream);*/
});
server.listen(8000, function() {
  console.log('server bound');
});

server.on('data', function(data) {
  console.log(data);
});
