const express = require('express');

const app = express();

app.set('view engine', 'ejs');
app.use(express.static('public'));

app.listen(3000);

app.get('/', (req, res) => {
    res.render('home', { title: 'Home page' });
});

app.get('/about', (req, res) => {
    res.render('about', { title: 'About page' });
});

app.get('/catalog', (req, res) => {
    res.render('catalog', { title: 'Catalog page' });
});

app.get('/contact', (req, res) => {
    res.render('contact', { title: 'Contact page' });
});

app.get('/login', (req, res) => {
    res.render('login', { title: 'Login page' });
});

app.get('/register', (req, res) => {
    res.render('register', { title: 'Register page' });
});

app.get('/upload', (req, res) => {
    res.render('upload', { title: 'Upload page' });
});

app.use((req, res) => {
    res.status(404).render('404', { title: 'Not found' });
})
