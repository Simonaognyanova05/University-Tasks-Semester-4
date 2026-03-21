const express = require('express');
const serviceController = require('../controllers/serviceController');


const router = express.Router();

router.get('/', serviceController.service_index);

router.get('/create', serviceController.service_create_get);

router.post('/', serviceController.service_create_post);


router.get('/:id', serviceController.service_details);

router.delete('/:id', serviceController.service_details_delete);



module.exports = router;