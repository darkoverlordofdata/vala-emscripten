/**
 * Expose commands with gulp for use by WebStorm
 *
 */
var gulp = require('gulp');
var shell = require('gulp-shell');

gulp.task('build', shell.task(['npm run build']));
gulp.task('clean', shell.task(['npm run clean']));
gulp.task('publish', function() {
  var ghPages = require('gulp-gh-pages');
  return gulp.src('./web/**/*')
    .pipe(ghPages());
});



