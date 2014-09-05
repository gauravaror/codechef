var app = angular.module('plunker', []);
 
app.controller('ArticleDetailController', ['$scope', '$rootScope','$location', function ($scope, $rootScope,$location) {
  $scope.name = 'World';
  $scope.urll = $location.absUrl();
  $scope.urlll = $location.protocol();
  $scope.go = function() {

    location.href = "/herethere";
    //alert("lfd");
  }
}]);

app.run(['$rootScope', '$location', function ($rootScope, $location) {

  var _preventNavigation = false;
  var _preventNavigationUrl = null;

  $rootScope.allowNavigation = function() {
    _preventNavigation = false;
  };

  $rootScope.preventNavigation = function() {
    _preventNavigation = true;
    _preventNavigationUrl = $location.absUrl();
  }

  $rootScope.$on('$locationChangeStart', function (event, newUrl, oldUrl) {
    // Allow navigation if our old url wasn't where we prevented navigation from
   /* if (_preventNavigationUrl != oldUrl || _preventNavigationUrl === null) {
      $rootScope.allowNavigation();
      return;
    }*/

    if (_preventNavigation && !confirm("You have unsaved changes, do you want to continue?")) {
      alert($location.absUrl()+" s "+$location.url());
      event.preventDefault();
    }
    else {
		$location.$$parse(newUrl);
       alert($location.absUrl()+" d "+$location.url());
      $rootScope.allowNavigation();
    }
  });
}]);




