const Service = require('../models/service');

const service_index = (req, res) => {
    Service.find().sort({ createdAt: -1 })
        .then(result => {
            res.render('index', { title: 'Services', services: result });
        })
        .catch(err => {
            console.log(err);
        });
};

const service_create_get = (req, res) => {
    res.render('create', { title: 'Create a new Blog' });
}

const service_create_post = (req, res) => {
    const service = new Service(req.body);

    service.save()
        .then(result => {
            res.redirect('/services');
        })
        .catch(err => {
            console.log(err);
        })
};

const service_details = (req, res) => {
    const id = req.params.id;

    Service.findById(id)
        .then(result => {
            res.render('details', { title: 'Product Details', service: result });
        })
        .catch(err => {
            console.log(err);
        })
};

const service_details_delete = (req, res) => {
    const id = req.params.id;

    Service.findByIdAndDelete(id)
        .then(result => {
            res.json({ redirect: '/catalog' });
        })
        .catch(err => {
            console.log(err);
        })
};

module.exports = {
    service_index,
    service_create_get,
    service_create_post,
    service_details,
    service_details_delete
}