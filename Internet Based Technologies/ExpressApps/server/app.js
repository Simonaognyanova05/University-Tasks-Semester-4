const express = require('express');
const mongoose = require('mongoose');
const Service = require('./models/service');
const serviceRouter = require('./routes/servicesRoute');

const app = express();

const dbURL = 'mongodb+srv://SimonaOgnyanova:123Simona2005@rent-hand.fcxtivy.mongodb.net/';
mongoose.connect(dbURL)
    .then(() => {
        app.listen(3000);
    }).catch((err) => {
        console.log(err);
    })

app.set('view engine', 'ejs');
app.use(express.urlencoded({ extanded: true }));
app.use(express.static('public'));


app.use((req, res, next) => {
    console.log('host: ', req.hostname);
    next();
});

app.get('/add-service', (req, res) => {
    const service = new Service({
        title: 'Математика',
        description: 'Уроци по интеграли',
        location: 'Пловдив',
        price: 25,
    });

    service.save()
        .then((result) => res.send(result))
        .catch(err => console.log(err));
});

app.get('/all-services', (req, res) => {
    Service.find()
        .then(result => {
            res.send(result);
        })
        .catch(err => {
            console.log(err);
        })
});

app.get('/single-service', (req, res) => {
    Service.findById('69bacb511f0b99b5d5cbe292')
        .then(result => {
            res.send(result);
        })
        .catch(err => {
            console.log(err);
        })
})

app.get('/', (req, res) => {
    res.redirect('/services');
});


app.get('/about', (req, res) => {
    res.render('about', { title: 'About Us' });
});

app.get('/about-us', (req, res) => {
    res.redirect('/about');
});

app.use('/services', serviceRouter);

app.use((req, res) => {
    res.status(404).render('404', { title: '404' });
});