/*
 * Inspired by: http://stackoverflow.com/questions/4360060/video-streaming-with-html-5-via-node-js
 */
 
var https = require('https'),
    fs = require('fs'),
    util = require('util'),
    tls = require('tls'),
    ytdl = require('ytdl');


var options = {
  key: fs.readFileSync('key.pem'),
  cert: fs.readFileSync('key-cert.pem')
};

var cleartextStream = https.createServer(options,function (req, res) {
//  var path = 'video.mp4';
  var path = "."+req.url;
  console.log(path);
  var stat;
  try {
      stat = fs.statSync(path);
  var total = stat.size;
  if (req.headers['range']) {
    nowsend(req,res,path,total);
  } else {
    console.log('ALL: ' + total);
    res.writeHead(200, { 'Content-Length': total, 'Content-Type': 'video/mp4' });
    fs.createReadStream(path).pipe(res);
  }
    }
    catch(err) {
        console.log(err);
        ytdl(req.headers['referer'],{ filter: function(format) { return format.container === 'mp4'; } }).pipe(fs.createWriteStream(path));
        console.log('Opened FIle now' );
        letsexecute = function() {
            stat = fs.statSync(path);
            
            var end = stat.size;
            console.log("now getting the end: "+end);
            if (req.headers['range']) {
                var total = req.headers.range.replace(/bytes=/, "").split("-")[1];
                nowsend(req,res,path,total,end);    
            }
        }
        setTimeout(letsexecute,30000);
  }
}).listen(8000, '127.0.0.1');
console.log('Server running at https://127.0.0.1:8000/');

nowsend = function (req,res,path,total,end1){
    var range = req.headers.range;
    var parts = range.replace(/bytes=/, "").split("-");
    var partialstart = parts[0];
    var partialend = parts[1];
 
    var start = parseInt(partialstart, 10);
    var end = partialend ? parseInt(partialend, 10) : total-1;
    var chunksize = (end-start)+1;
    console.log('RANGE: ' + start + ' - ' + end + ' = ' + chunksize);
    console.log('Partial: ' + partialend +' total '+total+' end1 '+ end1);
    var orignaltotal = total
    if (end1) {
        end = partialend;
        total = partialend;
    }
    try {
        if (orignaltotal == 0)  {
            throw new Error("No content to let it go to youtube");
        }
        res.writeHead(206, { 'Content-Range': 'bytes ' + start + '-' + end + '/' + total, 'Accept-Ranges': 'bytes', 'Content-Length': chunksize, 'Content-Type': 'video/mp4' });
        fs.createReadStream(path).pipe(res);
    }
    catch (err) {
        console.log("problem sending downloading file"+ err)
        res.statusCode = 500;
        res.end();
    }
}
