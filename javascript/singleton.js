const Singleton = (function() {
  // Instance stores a reference to Singleton
  let instance;

  function init() {
    // Private variables
    let privateVariable = 2;
    let privateRandomNumber = privateVariable * Math.random();

    // Private method
    function privateMethod() {
      console.log('I am a private method');
    }

    // Public method
    function publicMethod() {
      console.log('I am a public method');
    }

    return {
      publicMethod: publicMethod,
      publicProperty: 'I am a public property',
      getPrivateRandomVariable: function() {
        return privateRandomNumber;
      }
    };
  }

  // Get instance
  function getInstance() {
    if (!instance) {
      instance = init();
    }
    return instance;
  }

  // Expose necessary methods
  return {
    getInstance: getInstance
  };
})();

// test
let instanceA = Singleton.getInstance();
instanceA.publicMethod();
let instanceB = Singleton.getInstance();
console.log(instanceA === instanceB);
