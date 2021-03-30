<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'junhpark' );
// 아이디

/** MySQL database password */
define( 'DB_PASSWORD', '1234' );
// 비밀번호

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );
// 쿠버네티스에는  여러 service마다 ip가 다르게 할당되어있고 서비스 이름을  넣으면 쿠버네티스의 dns 서버가 지금 열려있는 모든 ip를 조회해서mysql에 해당하는 ip로 대체시켜준다.

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );


///////////////////////////////////////////////////////////////////////////////

/*
 * wordpress key generator
 */

define('AUTH_KEY',         '7L1UH99_;{904Ly=Tc+dDUELgUX}x%V0HyIrN];P<WYuVwh6{:|GJ`2zY)5}07<6');
define('SECURE_AUTH_KEY',  '<p]aX]fUs)|l[~Y}_Og-CVvJ`m0Gp=MbYV%3@ ;I-RzF+2%o.+!?9I#&Av33P{3R');
define('LOGGED_IN_KEY',    'j]kw6q:|0*{j<CQz(KgWMYD6g(^K;5K-~CE*@M`>IRj-&|lb&q{_RZR>sWl@&?*H');
define('NONCE_KEY',        '=#`8*a|c~M*=X$]pn1@G7Kn_03*Ju#Jg3(kO;Uv=[,e)e.]o^(r}MtHs,4s0(H;o');
define('AUTH_SALT',        'tL>1+&X~d7&}M6SQ4|RiJ|nf!jn~T+Tv&)d?b;-*+p$(r.m15pn*Fe6-|*=<)rIY');
define('SECURE_AUTH_SALT', 'NwnqWt$$fn_:vy?z?5G fuXh8ZcL56i|AzS~%@lsAp[^j;O5-6jKmhck+pKM-&Bj');
define('LOGGED_IN_SALT',   'McZt6R;nB[3fomEW-rq#6cr0t=JM6)GO}gqBQoTOf#=vDT(1:^+fZ`u%8gB,LvGS');
define('NONCE_SALT',       'LAGn4w%q8S)tXqj__781rm G,-d^Y,{)$cZu1^M2rRK1yK8,;((9;]oL6HQc[Oy$');

///////////////////////////////////////////////////////////////////////////////////////////


/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}
/**  임시적으로 파일을 생성및 제거하는 폴더 */
define('WP_TEMP_DIR', dirname(__FILE__) . '/wp-content/temp/');

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
