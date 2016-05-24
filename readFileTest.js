var fs=require("fs");
var saveDir = '/media/fighter/u_data/pic/';
fs.readFile("albums.json",'utf-8',function(err,data){  
    if(err){  
        console.log("error");  
    }else{  

        var albums = JSON.parse(data);
        console.log("length of albums "+albums.length)
        var i = 0;
        var j = 0;
        var that = this;
        var loop = function(){
            if(i< albums.length )
            {
                var album = albums[i];
                filedir = saveDir+album.title;
                if(j<album.imgurls.length){
                    var filepath = filedir+ album.imgurls[j].substr(album.imgurls[j].lastIndexOf("/"));
                    fs.exists(filepath,function (exists){
                        //console.log(filepath+" exists");
                        j++;
                        loop();
                    });
                }else{
                    i++;
                    j=0;
                    loop();
                }
            }else
            {
                console.log("end i :"+i);
            }
        }
        loop();

    }  
});  
