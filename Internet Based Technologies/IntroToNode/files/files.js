const fs = require('fs');


// Reading file
fs.readFile('./docs.txt', (err, data) => {
    if (err) {
        console.log(err);
    };

    console.log(data.toString());
});

// Writting file
fs.writeFile('./docs.txt', "hello, world", () => {
    console.log("the text was written");
});

fs.writeFile('./docs1.txt', "hello, again", () => {
    console.log("Next file was created successfully");
});

// directory
if (!fs.existsSync('./assets')) {
    fs.mkdir('./assets', (err) => {
        if (err) {
            console.log(err);
        }

        console.log("folder was created");
    })
} else{
    fs.rmdir("./assets", (err) => {
        if(err){
            console.log(err);
        }

        console.log('folder removed');
    })
};

// delete file
if(fs.existsSync('./docs1.txt')){
    fs.unlink('./docs1.txt', (err) => {
        if(err){
            console.log(err);
        }
        console.log("file was deleted");
    })
}
