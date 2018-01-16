var Module = (function() {

  var _privateMethod = function() {
    // private stuff
  };

  var publicMethod = function() {
    _privateMethod();
  };

  return {
    publicMethod: publicMethod
  };

})();
