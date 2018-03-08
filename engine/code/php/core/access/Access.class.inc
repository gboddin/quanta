<?php
/**
 * Class Access
 * This abstract class is representing an Access check from some
 * user, to some specific action, into some specific node.
 *
 *
 * @see NodeAccess
 * @see UserAccess
 */
abstract class Access implements AccessChecker {
  /**
   * @var Environment $env
   */
  protected $env;
  /**
   * @var Node $node
   */
  protected $node;
  /**
   * @var User $actor
   */
  protected $actor;

  /**
   * @var string $action
   */
  protected $action;

  /**
   * Constructs an access object.
   *
   * @param Environment $env
   *   The Environment.
   * @param array $vars
   */
  public function __construct(&$env, $action, $vars) {
    $this->env = $env;
    $this->actor = isset($vars['user']) ? $vars['user'] : UserFactory::current($env);
    $this->node = isset($vars['node']) ? $vars['node'] : NodeFactory::current($env);
    $this->action = trim(strtolower($action));
  }

  /**
   * Sets the action related to this access object.
   *
   * @param string $action
   *   The action.
   */
  public function setAction($action) {
    $this->action = $action;
  }

  /**
   * Gets the action related to this access object.
   *
   * @return string
   *   The action.
   */
  public function getAction() {
    return $this->action;
  }

  /**
   * Checks access to an action.
   */
  public abstract function checkAction();

}

/**
 * Interface AccessChecker
 * Simple interface for static methods.
 */
interface AccessChecker {
  /**
   * Check access to a certain action.
   *
   * @param Environment $env
   *   The Environment.
   * @param string $action
   *   The action to check.
   * @param array $vars
   *    Misc variables.
   *
   * @return bool
   *   True if user has access to the action.
   */
  static function check($env, $action, $vars = array());
}