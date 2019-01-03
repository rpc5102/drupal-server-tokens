Server Tokens 8.x
---------------

### About this Module
Based on [Token Issue #2021969](https://www.drupal.org/project/token/issues/2021969).

### Server Variables
**$_SERVER** is an array containing information such as headers, paths, and script locations. The entries in this array are created by the web server. There is no guarantee that every web server will provide any of these; servers may omit some, or provide others not listed here. That said, a large number of these variables are accounted for in the [» CGI/1.1 specification](http://www.faqs.org/rfcs/rfc3875), so you should be able to expect those.

See [http://php.net/manual/en/reserved.variables.server.php](http://php.net/manual/en/reserved.variables.server.php).

### Warning
This module has potential security implications.