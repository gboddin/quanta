<?php
  // Include the Environment module.
  require_once('core/environment/environment.module');

  // Include the Cache module.
  require_once('core/cache/cache.module');

  // Create a new Environment.
  $env = new Environment(NULL);

  if (!isset($_GET['doctor']) || !($_GET['doctor'] == 'setup')) {
    // Check if the current request is a file rendering request.
    $env->checkInstalled();
  }

  // Check if the current request is a file rendering request.
  $env->checkFile();

  // Load the environment.
  $env->load();

  // Start the user session.
  $env->startSession();

  // Run all system modules.
  $env->runModules();

  // Run the boot hook.
  $env->hook('boot');

  // Create the doctor.
  $doctor = new Doctor($env);


  // TODO: determine when to run doctor.
  if (isset($_GET['doctor']) && $_GET['doctor'] == 'setup') {
    $doctor->runSetup();
    exit;
  }

  // Check if there is any requested action.
  $env->checkActions();

  // Start page's standard index.html.
  $page = new Page($env, 'index.html');
  $env->setData('page', $page);

  // Run the init hook.
  $env->hook('init', array('page' => &$page));

  // Load page's included files (CSS / JS etc.)
  if (!isset($_REQUEST['ajax'])) {
    $page->loadIncludes();
  }

  // TODO: determine when to run doctor.
  if (isset($_GET['doctor'])) {
    $doctor->runDoctor();
    exit;
  }

  // Build the page's HTML code.
  $page->buildHTML();

  // Render the page.
  print $page->render();

  // Run the complete hook.
  $env->hook('complete');

  $node = NodeFactory::load($env, 'corsi-e-didattica');
  // End the bootstrap.
  exit();
?>
