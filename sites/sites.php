<?php 
/**
 * @file
 * Configuration file for Drupal's multi-site directory aliasing feature.
 *
 * Drupal searches for an appropriate configuration directory based on the
 * website's hostname and pathname. A detailed description of the rules for
 * discovering the configuration directory can be found in the comment
 * documentation in 'sites/default/default.settings.php'.
 *
 * This file allows you to define a set of aliases that map hostnames and
 * pathnames to configuration directories. These aliases are loaded prior to
 * scanning for directories, and they are exempt from the normal discovery
 * rules. The aliases are defined in an associative array named $sites, which
 * should look similar to the following:
 *
 * $sites = array(
 *   'devexample.com' => 'example.com',
 *   'localhost.example' => 'example.com',
 * );
 *
 * The above array will cause Drupal to look for a directory named
 * "example.com" in the sites directory whenever a request comes from
 * "example.com", "devexample.com", or "localhost/example". That is useful
 * on development servers, where the domain name may not be the same as the
 * domain of the live server. Since Drupal stores file paths into the database
 * (files, system table, etc.) this will ensure the paths are correct while
 * accessed on development servers.
 *
 * To use this file, copy and rename it such that its path plus filename is
 * 'sites/sites.php'. If you don't need to use multi-site directory aliasing,
 * then you can safely ignore this file, and Drupal will ignore it too.
 */

/**
 * Multi-site directory aliasing:
 *
 * Edit the lines below to define directory aliases. Remove the leading hash
 * signs to enable.
 */
$sites = array (
  'www.pna-research.albatrossdemos.com' => 'pna-research.albatrossdemos.com',
  'www.pna.albatrossdemos.com' => 'pna.albatrossdemos.com',
  'saphir.albatrossdemos.com' => 'uclasaphir.com',
  'saphir.dev.albatrossdemos.com' => 'uclasaphir.com',
  'www.uclasaphir.com' => 'uclasaphir.com',
  'www.projectnewamerica.o1.albatrossdemos.com' => 'projectnewamerica.o1.albatrossdemos.com',
  'www.projectnewamerica.albatrossdemos.com' => 'projectnewamerica.albatrossdemos.com',
  'projectnewamerica.biz' => 'projectnewamerica.com',
  'projectnewamerica.net' => 'projectnewamerica.com',
  'projectnewwest.biz' => 'projectnewamerica.com',
  'projectnewwest.com' => 'projectnewamerica.com',
  'projectnewwest.net' => 'projectnewamerica.com',
  'projectnewwest.org' => 'projectnewamerica.com',
  'www.projectnewamerica.biz' => 'projectnewamerica.com',
  'www.projectnewamerica.com' => 'projectnewamerica.com',
  'www.projectnewamerica.net' => 'projectnewamerica.com',
  'www.projectnewwest.biz' => 'projectnewamerica.com',
  'www.projectnewwest.com' => 'projectnewamerica.com',
  'www.projectnewwest.net' => 'projectnewamerica.com',
  'www.projectnewwest.org' => 'projectnewamerica.com',
);
