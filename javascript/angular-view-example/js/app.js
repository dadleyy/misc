(function( global ) {
  
'use strict';

var // module
    VEX,

    // controllers
    MainCntl,
    BookCntl,
    ChapterCntl;

VEX = angular.module('vex', [], function($routeProvider, $locationProvider) {
  
  $routeProvider.when('/Book/:bookId', {
    templateUrl: 'book.html',
    controller: BookCntl
  });
  
  $routeProvider.when('/Book/:bookId/ch/:chapterId', {
    templateUrl: 'chapter.html',
    controller: ChapterCntl
  });
 
  // configure html5 to get links working on jsfiddle
  $locationProvider.html5Mode(true);
  
});
 
MainCntl = function($scope, $route, $routeParams, $location) {
  $scope.$route = $route;
  $scope.$location = $location;
  $scope.$routeParams = $routeParams;
}
 
BookCntl = function($scope, $routeParams) {
  $scope.name = "BookCntl";
  $scope.params = $routeParams;
}
 
ChapterCntl = function($scope, $routeParams) {
  $scope.name = "ChapterCntl";
  $scope.params = $routeParams;
}
  
  
VEX
  .controller( 'MainCntl', MainCntl )
  .controller( 'BookCntl', BookCntl )
  .controller( 'ChapterCntl', ChapterCntl )
  
})( window );