<?php
/**
 * Implements hook_shadow_node_edit().
 *
 * @param Environment $env
 *   The Environment.
 *
 * @param array $vars
 *   Miscellaneous variables.
 */
function ecommerce_shadow_product_form($env, $vars) {
  $user = UserFactory::current($vars['env']);
  $node = NodeFactory::current($env);
  if (!$user->checkAccess($node, NODE_ACTION_EDIT)) {
    return FALSE;
  }
  $vars['shadow']->addTab('product information', file_get_contents('core/ecommerce/tpl/ecommerce_form.inc'), 2);
}

/**
 * Implements hook_init().
 *
 * @param Environment $env
 *   The Environment.
 *
 * @param array $vars
 *   Misc parameters.
 */
function ecommerce_init($env, $vars) {
  $vars['env']->addInclude('engine/code/php/contrib/ecommerce/js/ecommerce.js');
  $vars['env']->addInclude('engine/code/php/contrib/ecommerce/css/ecommerce.css');
}

/**
 * Implements hook_node_save().
 *
 * @param Environment $env
 *   The Environment.
 *
 * @param array $vars
 *   Mixed variables.
 */
function ecommerce_node_presave($env, $vars) {
  if (isset($vars['data']['price'])) {
    $vars['node']->json->price = $vars['data']['price'];
    $vars['node']->json->availability = $vars['data']['availability'];
    $vars['node']->json->stock = $vars['data']['stock'];
  }
}