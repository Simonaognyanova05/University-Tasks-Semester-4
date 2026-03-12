const fs = require('fs');

const readStream = fs.createReadStream("./text.txt", { encoding: 'utf8' });
const writeStream = fs.createWriteStream('./text1.txt', { encoding: 'utf8' });

// readStream.on('data', (chunk) => {
//     console.log("--- NEW CHUNK ---");
//     console.log(chunk);
//     writeStream.write("\n NEW CHUNK \n");
//     writeStream.write(chunk);
// });

// PIPING
readStream.pipe(writeStream);