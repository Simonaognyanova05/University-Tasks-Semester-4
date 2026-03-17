const express = require('express');

const app = express();

app.set('view engine', 'ejs');
app.use(express.static('public'));

app.use((req, res, next) => {
    console.log('host: ', req.hostname);
    next();
})

app.get('/', (req, res) => {

    const blogs = [
        { title: "Blog 1", snippet: 'This is blog 1' },
        { title: "Blog 2", snippet: 'This is blog 2' },
        { title: "Blog 3", snippet: 'This is blog 3' },
    ];

    res.render('index', { title: 'Home', blogs });
});

app.get('/about', (req, res) => {
    res.render('about', { title: 'About Us' });
});

app.get('/about-us', (req, res) => {
    res.redirect('/about');
});

app.get('/blogs/create', (req, res) => {
    res.render('create', { title: 'Create a new Blog' });
});

app.use((req, res) => {
    res.status(404).render('404', { title: '404' });
});
app.listen(3000);