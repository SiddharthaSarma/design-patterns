/* Structural pattern */

function Beverage(name, temperature) {
  this.name = name;
  this.temperature = temperature;
}

Beverage.prototype.drink = function() {
  console.log(`I am drinking ${this.temperature} ${this.name}`);
};

function Coffee(type) {
  Beverage.call(this, 'coffee', 'hot');
  this.type = type;
}

Coffee.prototype = Object.create(Beverage.prototype);

Coffee.prototype.sip = function() {
  console.log(`I am drinking ${this.type} ${this.name}`);
};

// Example
let beverageObj = new Beverage('water', 'cold');
let coffeeObj = new Coffee('dark roast');
beverageObj.drink();
coffeeObj.sip();
