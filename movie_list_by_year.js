const https = require('https');
async function getMovieList(year) {
    // write your code here
    // API endpoint: https://jsonmock.hackerrank.com/api/movies?Year=<year>

    var options = {
        'method': 'GET',
        'hostname': 'jsonmock.hackerrank.com',
        'path': `/api/movies?Year=${year}`,
        'headers': {
        },
        'maxRedirects': 20
      };
      
      var req = https.request(options, function (res) {
        var chunks = [];
      
        res.on("data", function (chunk) {
          chunks.push(chunk);
          let arr = JSON.parse(chunk);
          let arr2 = [...arr.data];
          let arr3 = arr2.map((data)=>{
              return data.Title;
          })
          console.log(arr3)
        });
      
        res.on("end", function (chunk) {
          var body = Buffer.concat(chunks);
          //console.log(body.toString());
        });
      
        res.on("error", function (error) {
          console.error(error);
        });
      });
      
      req.end();
    }

    getMovieList(2013)
