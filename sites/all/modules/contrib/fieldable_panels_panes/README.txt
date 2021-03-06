Fieldable Panel Panes support multiple bundles; they can be
created in admin/structure/fieldable-panels-panes/add.

Bundles can also be created in a module via hook_entity_info_alter(). The code
will look something like this:

function MYMODULE_entity_info_alter(&$entity_info) {
  $entity_info['fieldable_panels_pane']['bundles']['my_bundle_name'] = array(
    'label' => t('My bundle name'),
    'pane category' => t('My category name'),
    'pane top level' => FALSE, // set to true to make this show as a top level icon
    'pane icon' => '/path/to/custom/icon/for/this/pane.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/%fieldable_panels_panes_type',
      'bundle argument' => 5,
      // Note that this has all _ replaced with - from the bundle name.
      'real path' => 'admin/structure/fieldable-panels-panes/my-bundle-name',
      'access arguments' => array('administer fieldable panels panes'),
    ),
  );
}

Fields are then added to your bundle as normal through the Manage Fields and
Display Fields tabs in the UI.

You can use this hook to rename or remove the default bundle but remember that
doing so will break any content currently using that bundle. If you do this
be sure to also fix any content already using it. It is recommended that you
use the bundle management UI in admin/structure/fiedlable-panels-panes so you
don't have to maintain this yourself.
