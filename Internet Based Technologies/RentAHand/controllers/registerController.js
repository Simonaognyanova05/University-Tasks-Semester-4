const bcrypt = require('bcrypt');
const User = require('../models/user');

const register_get = (req, res) => {
    res.render('register', { title: 'Register page' });
};

const register_post = (req, res) => {
    const { username, email, password } = req.body;
    bcrypt.hash(password, 10)
        .then(hash => {

            const user = new User({ username: username, email: email, password: hash });
            user.save()
                .then(result => {
                    res.redirect('/');
                })
                .catch(err => {
                    console.log(err);
                })
        })
        .catch(e => {
            console.log(e);
        })
}

module.exports = {
    register_get,
    register_post
};