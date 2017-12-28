/*
The Prototype Pattern creates new objects, but rather than creating non-initialized objects it returns objects that are initialized with values it copied from a prototype - or sample - object. The Prototype pattern is also referred to as the Properties pattern.

An example of where the Prototype pattern is useful is the initialization of business objects with values that match the default values in the database. The prototype object holds the default values that are copied over into a newly created business object.

Classical languages rarely use the Prototype pattern, but JavaScript being a prototypal language uses this pattern in the construction of new objects and their prototypes.

The objects participating in this pattern are:

Client -- In sample code: the run() function.
    creates a new object by asking a prototype to clone itself
Prototype -- In sample code: CustomerPrototype
    creates an interfaces to clone itself
Clones -- In sample code: Customer
    the cloned objects that are being created


*/
function Customer(firstName, lastName, status) {
  this.firstName = firstName;
  this.lastName = lastName;
  this.status = status;
  this.say = function() {
    alert(`${this.firstName} ${this.lastName} is ${this.status}`);
  };
}

function CustomerPrototype(proto) {
  this.proto = proto;

  this.clone = function() {
    let customer = new Customer();
    customer.firstName = proto.firstName;
    customer.lastName = proto.lastName;
    customer.status = proto.status;
  };
}

function run() {
  let proto = new Customer('A', 'B', 'pending');
  let prototype = new CustomerPrototype(proto);

  let customer = prototype.clone();
  customer.say();
}
