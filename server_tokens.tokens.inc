<?php

use Drupal\Core\Render\BubbleableMetadata;

 /**
 * Implements hook_token_info().
 */
function server_tokens_token_info() {

  $types['server'] = array(
    'name' => t('Server'),
    'description' => t('$_SERVER VARIABLES')
  );

  $tokens['admin'] = array(
    'name' => t('SERVER_ADMIN'),
    'description' => t('The value given to the SERVER_ADMIN (for Apache) directive in the web server configuration file. If the script is running on a virtual host, this will be the value defined for that virtual host.')
  );

  $tokens['self'] = array(
    'name' => t('PHP_SELF'),
    'description' => t('The filename of the currently executing script, relative to the document root.')
  );

  $tokens['script'] = array(
    'name' => t('SCRIPT_NAME'),
    'description' => t('Contains the current script\'s path. This is useful for pages which need to point to themselves. ')
  );

  $tokens['gateway'] = array(
    'name' => t('GATEWAY_INTERFACE'),
    'description' => t('What revision of the CGI specification the server is using; i.e. \'CGI/1.1\'.')
  );

  $tokens['address'] = array(
    'name' => t('SERVER_ADDR'),
    'description' => t('The IP address of the server under which the current script is executing.')
  );

  $tokens['name'] = array(
    'name' => t('SERVER_NAME'),
    'description' => t('The name of the server host under which the current script is executing. If the script is running on a virtual host, this will be the value defined for that virtual host.')
  );

  $tokens['software'] = array(
    'name' => t('SERVER_SOFTWARE'),
    'description' => t('Server identification string, given in the headers when responding to requests.')
  );

  $tokens['protocol'] = array(
    'name' => t('SERVER_PROTOCOL'),
    'description' => t('Name and revision of the information protocol via which the page was requested; i.e. \'HTTP/1.0\';')
  );

  $tokens['request:method'] = array(
    'name' => t('REQUEST_METHOD'),
    'description' => t('Which request method was used to access the page; i.e. \'GET\', \'HEAD\', \'POST\', \'PUT\'.')
  );

  $tokens['request:time'] = array(
    'name' => t('REQUEST_TIME'),
    'description' => t('The timestamp of the start of the request. Available since PHP 5.1.0.')
  );

  $tokens['request:time:float'] = array(
    'name' => t('REQUEST_TIME_FLOAT'),
    'description' => t('The timestamp of the start of the request, with microsecond precision. Available since PHP 5.4.0.')
  );

  $tokens['request:scheme'] = array(
    'name' => t('REQUEST_SCHEME'),
    'description' => t('The URI which was given in order to access this page; for instance, \'/index.html\'.')
  );

  $tokens['request:uri'] = array(
    'name' => t('REQUEST_URI'),
    'description' => t('The URI which was given in order to access this page; for instance, \'/index.html\'.')
  );

  $tokens['query'] = array(
    'name' => t('QUERY_STRING'),
    'description' => t('The query string, if any, via which the page was accessed.')
  );

  $tokens['root'] = array(
    'name' => t('DOCUMENT_ROOT'),
    'description' => t('The document root directory under which the current script is executing, as defined in the server\'s configuration file.')
  );

  $tokens['accept'] = array(
    'name' => t('HTTP_ACCEPT'),
    'description' => t('Contents of the Accept: header from the current request, if there is one.')
  );

  $tokens['accept:charset'] = array(
    'name' => t('HTTP_ACCEPT_CHARSET'),
    'description' => t('Contents of the Accept-Charset: header from the current request, if there is one. Example: \'iso-8859-1,*,utf-8\'.')
  );

  $tokens['accept:encoding'] = array(
    'name' => t('HTTP_ACCEPT_ENCODING'),
    'description' => t('Contents of the Accept-Encoding: header from the current request, if there is one. Example: \'gzip\'.')
  );

  $tokens['accept:language'] = array(
    'name' => t('HTTP_ACCEPT_LANGUAGE'),
    'description' => t('Contents of the Accept-Language: header from the current request, if there is one. Example: \'en\'.')
  );

  $tokens['connection'] = array(
    'name' => t('HTTP_CONNECTION'),
    'description' => t('Contents of the Connection: header from the current request, if there is one. Example: \'Keep-Alive\'.')
  );

  $tokens['host'] = array(
    'name' => t('HTTP_HOST'),
    'description' => t('Contents of the Host: header from the current request, if there is one.')
  );

  $tokens['referrer'] = array(
    'name' => t('HTTP_REFERER'),
    'description' => t('The address of the page (if any) which referred the user agent to the current page. This is set by the user agent. Not all user agents will set this, and some provide the ability to modify HTTP_REFERER as a feature. In short, it cannot really be trusted.')
  );

  $tokens['useragent'] = array(
    'name' => t('HTTP_USER_AGENT'),
    'description' => t('Contents of the User-Agent: header from the current request, if there is one. This is a string denoting the user agent being which is accessing the page.')
  );

  $tokens['https'] = array(
    'name' => t('HTTPS'),
    'description' => t('Set to a non-empty value if the script was queried through the HTTPS protocol.')
  );

  $tokens['remote:addr'] = array(
    'name' => t('REMOTE_ADDR'),
    'description' => t('The IP address from which the user is viewing the current page.')
  );

  $tokens['remote:host'] = array(
    'name' => t('REMOTE_HOST'),
    'description' => t('The Host name from which the user is viewing the current page. The reverse dns lookup is based on the REMOTE_ADDR of the user.')
  );

  $tokens['remote:port'] = array(
    'name' => t('REMOTE_PORT'),
    'description' => t('The port being used on the user\'s machine to communicate with the web server.')
  );

  return array(
    'types' => $types,
    'tokens' => array(
      'server' => $tokens
    )
  );
}

/**
 * Implements hook_tokens().
 */
function server_tokens_tokens($type, $tokens, array $data, array $options, BubbleableMetadata $bubbleable_metadata) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if($type == 'server') {
    foreach ($tokens as $name => $original) {
      switch ($name){
        case 'admin':
          $replacements[$original] = _get_server_var('SERVER_ADMIN');
          break;
        case 'self':
          $replacements[$original] = _get_server_var('PHP_SELF');
          break;
        case 'script':
          $replacements[$original] = _get_server_var('SCRIPT_NAME');
          break;
        case 'gateway':
          $replacements[$original] = _get_server_var('GATEWAY_INTERFACE');
          break;
        case 'address':
          $replacements[$original] = _get_server_var('SERVER_ADDR');
          break;
        case 'name':
          $replacements[$original] = _get_server_var('SERVER_NAME');
          break;
        case 'software':
          $replacements[$original] = _get_server_var('SERVER_SOFTWARE');
          break;
        case 'protocol':
          $replacements[$original] = _get_server_var('SERVER_PROTOCOL');
          break;
        case 'request:method':
          $replacements[$original] = _get_server_var('REQUEST_METHOD');
          break;
        case 'request:time':
          $replacements[$original] = _get_server_var('REQUEST_TIME');
          break;
        case 'request:time:float':
          $replacements[$original] = _get_server_var('REQUEST_TIME_FLOAT');
          break;
        case 'request:scheme':
          $replacements[$original] = _get_server_var('REQUEST_SCHEME');
          break;
        case 'request:uri':
          $replacements[$original] = _get_server_var('REQUEST_URI');
          break;
        case 'query':
          $replacements[$original] = _get_server_var('QUERY_STRING');
          break;
        case 'root':
          $replacements[$original] = _get_server_var('DOCUMENT_ROOT');
          break;
        case 'accept':
          $replacements[$original] = _get_server_var('HTTP_ACCEPT');
          break;
        case 'accept:charset':
          $replacements[$original] = _get_server_var('HTTP_ACCEPT_CHARSET');
          break;
        case 'accept:encoding':
          $replacements[$original] = _get_server_var('HTTP_ACCEPT_ENCODING');
          break;
        case 'accept:language':
          $replacements[$original] = _get_server_var('HTTP_ACCEPT_LANGUAGE');
          break;
        case 'connection':
          $replacements[$original] = _get_server_var('HTTP_CONNECTION');
          break;
        case 'host':
          $replacements[$original] = _get_server_var('HTTP_HOST');
          break;
        case 'referrer':
          $replacements[$original] = _get_server_var('HTTP_REFERER');
          break;
        case 'useragent':
          $replacements[$original] = _get_server_var('HTTP_USER_AGENT');
          break;
        case 'https':
          $replacements[$original] = _get_server_var('HTTPS');
          break;
        case 'remote:addr':
          $replacements[$original] = _get_server_var('REMOTE_ADDR');
          break;
        case 'remote:host':
          $replacements[$original] = _get_server_var('REMOTE_HOST');
          break;
        case 'remote:port':
          $replacements[$original] = _get_server_var('REMOTE_PORT');
          break;
      }
    }
  }
  return $replacements;
}

function _get_server_var($var, $filter = 0){
  $server = $_SERVER[$var];
  if(!empty($server) && $filter){
    return filter_xss($_SERVER[$var]); 
  } else {
    return empty($_SERVER[$var]) ? '' : $_SERVER[$var];
  }
}