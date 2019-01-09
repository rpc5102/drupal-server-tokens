Server Tokens 8.x-1.x
---------------

### About this Module
Based on [Token Issue #2021969](https://www.drupal.org/project/token/issues/2021969).

### Server Variables
**$_SERVER** is an array containing information such as headers, paths, and script locations. The entries in this array are created by the web server. There is no guarantee that every web server will provide any of these; servers may omit some, or provide others not listed here. That said, a large number of these variables are accounted for in the [» CGI/1.1 specification](http://www.faqs.org/rfcs/rfc3875), so you should be able to expect those.

See: [http://php.net/manual/en/reserved.variables.server.php](http://php.net/manual/en/reserved.variables.server.php).

### Requirements
- [drupal/token](https://www.drupal.org/project/token)

### Warning
This module has potential security implications! It may be used to display information that can compromise the server that your site is running on. Only allow trusted roles to view this information.

### Available Tokens
|Token|Name|
|:--- |:--- |
|[server:accept]|HTTP_ACCEPT|
|[server:accept :charset]|HTTP_ACCEPT_CHARSET|
|[server:accept :encoding]|HTTP_ACCEPT_ENCODING|
|[server:accept :language]|HTTP_ACCEPT_LANGUAGE|
|[server:address]|SERVER_ADDR|
|[server:admin]|SERVER_ADMIN|
|[server:connection]|HTTP_CONNECTION|
|[server:gateway]|GATEWAY_INTERFACE|
|[server:host]|HTTP_HOST|
|[server:https]|HTTPS|
|[server:name]|SERVER_NAME|
|[server:protocol]|SERVER_PROTOCOL|
|[server:query]|QUERY_STRING|
|[server:request:method]|REQUEST_METHOD|
|[server:request:scheme]|REQUEST_SCHEME|
|[server:request:time]|REQUEST_TIME|
|[server:request:time:float]|REQUEST_TIME_FLOAT|
|[server:request:uri]|REQUEST_URI|
|[server:referrer]|HTTP_REFERER|
|[server:remote:addr]|REMOTE_ADDR|
|[server:remote:host]|REMOTE_HOST|
|[server:remote:port]|REMOTE_PORT|
|[server:root]|DOCUMENT_ROOT|
|[server:script]|SCRIPT_NAME|
|[server:self]|PHP_SELF|
|[server:software]|SERVER_SOFTWARE|
|[server:useragent]|HTTP_USER_AGENT|
