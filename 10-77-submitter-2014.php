#!/usr/bin/php
<?php
/**
 *
 * CProgramming website submitter
 * @author Senorsen
 * @description sen@senorsen.com , please see license
 * @link http://www.senorsen.com
 * @version 2014-04-21 Mon 22:40:32
 * @version 2014-04-22 Tue 02:01:49
 * @version 2014-04-22 Tue 12:35:48
 *
 **/
$tmp_path = '/tmp/';    // must with a suffix slash ('/')
$tmp_file = tempnam($tmp_path, "SEN_CP_TMP");
$server_host = "10.77.30.138";
$server = "http://$server_host/";
if ($argc == 1) {
    echo "Usage: ./submitter.php YOUR_USER_ID [YOUR_PASSWORD]\n";
    echo "Put me in Richard1122's CProgram...-ZJU directory.\n";
    echo "Not tested since 2014-09\n";
    echo "Author: Senorsen. Without any copyright, but follow the LICENSE.\n";
    echo "\n";
    exit(0);
}
if ($argc == 2) {
    $stuid = $passwd = $argv[1];
}
if ($argc == 3) {
    $stuid = $argv[1];
    $passwd = $argv[2];
}
echo "CProgramming Submitter by Senorsen - sen@senorsen.com\n";
echo "Please see the LICENSE.\n";
$login_ret = login($stuid, $passwd);
getannounce($login_ret);
$classes = getclass($login_ret);
echo "\n";
echo "+---------------------------------------------+\n";
foreach ($classes as $key => $value) {
    printf("ID: %2d %5s %10s %13s %12s\n", $key, $value->id, $value->no, $value->name, $value->teacher);
}
echo "+---------------------------------------------+\n";
sleep(1);
foreach ($classes as $key => $value) {
    echo "Try $key-$value->id : ";
    $lianxis = getlianxi($value->id);
    if ($lianxis == FALSE) {
        continue;
    }
    echo "Your practices: \n";
    foreach ($lianxis as $kk => $vv) {
        printf("ID: %2d  %4s  %s\t %s  %s\n", $kk, $vv->id, $vv->no, $vv->from, $vv->to);
    }
    sleep(2);
    foreach ($lianxis as $kk => $vv) {
        echo "Try practice $kk-$vv->id:\n";
        sleep(0.5);
        $problemset = getproblemset($vv->id);
        $nas = array();
        foreach ($problemset as $vvv) {
            $acnastr = $vvv->score == 100 ? 'AC' : 'NA';
            $acnaclr = $acnastr == 'AC' ? 32 : 31;
            echo exec("echo \"[\\033[0;$acnaclr;49m$acnastr\\033[0;0;0m]\"");
            printf("  %05d  %3d  %s\n", $vvv->id, $vvv->score, $vvv->title);
            if ($acnastr == 'NA') {
                array_push($nas, $vvv);
            }
        }
        echo "Proceed with file copy? (to homework_{$vv->id}_$stuid/) [y/N]:\n";
        if (inputstr() == 'y') {
            $p_file_copy = 1;
            $loop_arr = $problemset;
            @mkdir("homework_{$vv->id}_$stuid");
        } else {
            $p_file_copy = 0;
            $loop_arr = $nas;
        }
        foreach ($loop_arr as $vvv) {
            echo "Fetch for $vvv->vid-$vvv->id : $vvv->title ";
            $problem_desc = htmltotext(getproblem($vvv->link));
            echo ".\n";
            $src_flag = 0;
            ready_for_upload:
            if (!file_exists($vvv->id . '/' . $vvv->id . '.c')) {
                $src_flag = 1;
                @mkdir($vvv->id);
                $desc_searches = array('/\)\{/', "/\\)\n\\{/", '/"stdio\.h"/');
                $desc_replaces = array(') {', ') {', '<stdio.h>');
                $problem_desc = preg_replace($desc_searches, $desc_replaces, $problem_desc);
                file_put_contents("$vvv->id/README.txt", $vvv->title . "\n\n" . $problem_desc . "\n");
                echo "Terrible >_< File not exist.\n";
                echo "So you should solve this problem: (press Enter/Return key to see the problem)\n";
                waitforret();
                preg_match('/(\#include[\s\S]+)$/', $problem_desc, $matches_src);
                $demo_src = $matches_src[1];
                // Hey it should be 小森森/Senorsen's code style!!
                file_put_contents("$vvv->id/{$vvv->id}_not_finished.c", $demo_src);
                echo $problem_desc . "\n";
                echo "=v= When you finished this code at $vvv->id/{$vvv->id}_not_finished.c, \n";
                echo "    Work hard to HIT your Enter/Return key!\n";
                echo "Find $vvv->id/{$vvv->id}_not_finished.c, and it will be renamed automatically.\n";
                waitforret();
                rename("$vvv->id/{$vvv->id}_not_finished.c", "$vvv->id/$vvv->id.c");
                goto ready_for_upload;
            } else {
                echo "Uploading $vvv->id/$vvv->id.c, please wait...\n";
                if (FALSE == uploadsrc($vvv->id, "$vvv->id/$vvv->id.c")) {
                    echo "Error: cannot upload. \n";
                    echo "fatal error.\n";
                    echo "If this problem persists, please contact me.\n";
                    exit(4);
                } else {
                    $timer = 10;
                    while ($timer) {
                        $timer--;
                        $problem_result = getresult();
                        echo "Code: $problem_result\n";
                        if ($problem_result == '运行完毕') break;
                        sleep(1);
                    }
                    if ($problem_result != '运行完毕') {
                        echo "Your source code is incorrect? \n";
                        echo "Try to correct it, and then press Enter/Return to retry.\n";
                        waitforret();
                        goto ready_for_upload;
                    }
                    if ($src_flag) {
                        echo "It seems that my repo does not have your code.\n";
                        echo "Would you like to share (pull request) this to me?\n";
                        echo "Pulling request of .c code is welcomed here!\n";
                    }
                    echo "$vvv->id $vvv->title Solved, AC!!\n";
                    if ($p_file_copy) {
                        copy("$vvv->id/$vvv->id.c", "homework_{$vv->id}_$stuid/$vvv->id.c");
                    }
                    sleep(1);
                }
            }
        }
        echo "Contest $vv->id OK!\n";
        if (count($nas) > 0) {
            $problemset = getproblemset($vv->id);
            foreach ($problemset as $vvv) {
                $acnastr = $vvv->score == 100 ? 'AC' : 'NA';
                $acnaclr = $acnastr == 'AC' ? 32 : 31;
                echo exec("echo \"[\\033[0;$acnaclr;49m$acnastr\\033[0;0;0m]\"");
                printf("  %05d  %3d  %s\n", $vvv->id, $vvv->score, $vvv->title);
            }
        }
        echo "Press Enter/Return to continue, or 'exit' and RET for exit!\n";
        if (waitforret()) {
            bye();
            exit(0);
        }
    }
    echo "Everything is OK!\n";
    echo "Author: Senorsen sen@senorsen.com\n";
}
bye();
function bye()
{
    global $tmp_file;
    echo "Bye~~\n";
    unlink($tmp_file);
}

function uploadsrc($prob_id, $file)
{
    $data = array(
        'MAX_FILE_SIZE' => '81920000',
        'prob_id' => $prob_id,
        'userfile' => '@' . __DIR__ . '/' . $file
    );
    $ret = curlf('student/submit_process.php', $data, 1);
    if (preg_match('/解答已经提交，请稍等/', $ret)) {
        preg_match('/url=(.+?)"/', $ret, $matches);
        sleep(2);
        curlf('student/' . $matches[1], null, 1);
        return TRUE;
    } else {
        return FALSE;
    }
}

function getresult()
{
    $ret = curlf('student/status.php', null, 1);
    preg_match_all('/<td align=center(.+?)\/td>/', $ret, $matches);
    $arr = array('运行中', '运行超时', '编译错误', '运行完毕');
    foreach ($arr as $value) {
        if (preg_match('/' . $value . '/', $matches[1][9])) return $value;
    }
    return 'UNKNOWN';
}

function getproblem($link)
{
    $ret = curlf('student/' . $link, null, 1);
    preg_match('/<code>([\s\S]+?)<\/code>/', $ret, $matches);
    $desc = $matches[1];
    return $desc;
}

function getproblemset($id)
{
    $data = "contest_id=$id&Submit=listproblem";
    $ret = curlf('student/listproblem.php', $data, 1);
    if (!preg_match('/题号/', $ret)) {
        echo "Error: cannot get problemset.\n";
        echo "If this problem persists, please contact me.\n";
        sleeptogether();
        return FALSE;
    } else {
        preg_match_all('/<td align=center>(\d+)/', $ret, $matches_number);
        preg_match_all('/<a style="text-decoration: none" href="show_problem.php\?cid=\d+\&pid=\d+\&pno=\d+">([\s\S]+?)<\/a>/', $ret, $matches_title);
        preg_match_all('/<a style="text-decoration: none" href="(show_problem.php\?cid=\d+\&pid=\d+\&pno=\d+)">/', $ret, $matches_link);
        $matches_number = $matches_number[1];
        $matches_title = $matches_title[1];
        $matches_link = $matches_link[1];
        $problems = array();
        $i = 0;
        $j = 0;
        foreach ($matches_number as $key => $value) {
            $key = intval($key);
            if ($i % 2 == 0) {
                $problems[$j++] = (object)array('id' => intval($value), 'score' => intval($matches_number[$key + 1]));
            }
            $i++;
        }
        $i = 0;
        foreach ($matches_link as $key => $value) {
            $key = intval($key);
            $problems[$i]->title = trim($matches_title[$key]);
            $problems[$i]->link = $matches_link[$key];
            $problems[$i]->vid = $i;
            $problems[$i]->contest_id = $id;
            $i++;
        }
        return $problems;
    }
}

function getlianxi($id)
{
    global $server;
    $data = "c_choose=$id&Submit=submit";
    curlf('student/studentchoose.php', $data, 1);
    $data = 'choose=lianxi&B1=%CC%E1%BD%BB';
    $ret = curlf('student/contestchoose.php', $data, 1);
    if (!preg_match('/请选择考试\/练习场次/', $ret)) {
        echo "Error: Cannot get practices.\n";
        echo "If this problem persists, please contact me.\n";
        sleeptogether();
        return FALSE;
    } else {
        $lianxis = array();
        preg_match_all('/<div align="center">(.*?)<\/div>/', $ret, $matches);
        $matches = $matches[1];
        for ($i = 0; $i < 5; $i++) unset($matches[$i]);
        foreach ($matches as $key => $value) {
            $key = intval($key);
            if (preg_match('/<input type="radio"/', $value)) {
                array_push($lianxis, (object)array(
                    'id' => $matches[$key + 1],
                    'no' => $matches[$key + 2],
                    'from' => $matches[$key + 3],
                    'to' => $matches[$key + 4]
                ));
            }
        }
        return $lianxis;
    }
}

function sleeptogether()
{
    echo "Now we sleep for 4s: ";
    for ($i = 1; $i <= 4; $i++) {
        sleep(1);
        echo $i . " ";
    }
    echo ".\n";
}

function getannounce($str)
{
    global $stuid;
    $ret = curlf('student/teacherannounce.php?userid=' . $stuid, null, 1);
    // echo "LENGTH" . strlen($ret);
    // 105 is empty
    if (strlen($ret) != 105) {
        echo "***ATTENTION***: You have some announcement in the website.\n";
        echo "If you think this important, please have a look \n";
        echo "     at the C Programming Practice website.\n";
        sleep(2);
    }
}

function getclass($str)
{
    $classes = array();
    preg_match_all('/<div align="center">(.*?)<\/div>/', $str, $matches);
    for ($i = 0; $i < 5; $i++) {
        unset($matches[1][$i]);
    }
    foreach ($matches[1] as $key => $value) {
        $key = intval($key);
        if (preg_match('/<input type="radio" name="c_choose"value="(\d+)">/', $value, $vmatches)) {
            array_push($classes, (object)array(
                'id' => $matches[1][$key + 1],
                'no' => $matches[1][$key + 2],
                'name' => $matches[1][$key + 3],
                'teacher' => $matches[1][$key + 4]
            ));
        }
    }
    return $classes;
}

function login($stuid, $passwd)
{
    global $tmp_file, $server_host;
    echo "Try login with stuid: $stuid ";
    $data = array(
        'user_id' => $stuid,
        'passwd' => $passwd,
        'submit1' => 'login',
    );
    $ret = curlf('student/studentcheck.php', $data, 2);
    if ($ret === FALSE) {
        echo "x\n";
        echo "Login failed, please check your network connection.\n";
        echo "If this problem persists, please contact me >_<\n";
        exit(2);
    } else {
        echo " ... [ok]\n";
        if (preg_match('/欢迎使用上机测试系统/', $ret)) {
            // 登录成功
            preg_match('/欢迎使用上机测试系统&nbsp;&nbsp;  (\d+)&nbsp;&nbsp;(.+?)</', $ret, $matches);
            echo "Login success! $matches[1] - $matches[2] \n";
            file_put_contents($tmp_file, file_get_contents($tmp_file) . "$server_host\tFALSE\t/\tFALSE\t0\tuser_id\t$stuid\n");
            return $ret;
        } else {
            echo "Login faild, please check your stuid & passwd.\n";
            echo "If this problem persists, please contact me >_<\n";
            exit(1);
        }
    }
}

function curlf($url, $data = null, $cookie_jar_type = 0, $other_headers = array(), $timeout = 30)
{
    global $tmp_file, $server;
    $url = $server . $url;
    $ua = "Senorsen's CProgramming file submitter";
    $url = mb_convert_encoding($url, 'utf-8', 'gbk');
    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_HEADER, false);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout / 2);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
    if (!empty($ua)) {
        curl_setopt($ch, CURLOPT_HTTPHEADER, array_merge(array("User-Agent: $ua", "X-Forwarded-For: 10.77.30.31"), $other_headers));
    }
    // cookie_jar_type:
    // 0 for doing nothing
    // 1 for read
    // 2 for write
    if ($cookie_jar_type == 1) {
        curl_setopt($ch, CURLOPT_COOKIEFILE, $tmp_file);
    }
    if ($cookie_jar_type == 2) {
        curl_setopt($ch, CURLOPT_COOKIEJAR, $tmp_file);
    }
    if (!is_null($data)) {
        //POST
        if (is_string($data)) {
            $data = mb_convert_encoding($data, 'gbk', 'utf-8');
            curl_setopt($ch, CURLOPT_POST, true);
            curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
        } else if (is_array($data)) {
            convert_arr_to_gbk($data);
            curl_setopt($ch, CURLOPT_POST, true);
            curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
        }
    }
    curl_setopt($ch, CURLOPT_TIMEOUT, $timeout);
    $str = curl_exec($ch);
    curl_close($ch);
    if (!is_null($str)) {
        $str = mb_convert_encoding($str, 'utf-8', 'gbk');
    } else {
        $str = FALSE;
    }
    return $str;
}

function convert_arr_to_gbk(&$obj)
{
    // note that xiao sensen won't pass me an unchangable variable.
    if (is_object($obj) || is_array($obj)) {
        // hey but I cannot convert the key.
        foreach ($obj as $key => &$value) {
            convert_arr_to_gbk($value);
        }
        return $obj;
    } else if (is_string($obj)) {
        return ($obj = mb_convert_encoding($obj, 'gbk', 'utf-8'));
    }
}

function htmltotext($str)
{
    $search = array('/(<br>|<br \/>)/',
        '/&(quot|#34);/', // 替换 HTML 实体
        '/&(amp|#38);/',
        '/&(lt|#60);/',
        '/&(gt|#62);/',
        '/&(nbsp|#160);/',
        '/&(iexcl|#161);/',
        '/&(cent|#162);/',
        '/&(pound|#163);/',
        '/&(copy|#169);/',
        '/&#(\\d+);/',
        '/' . "\x0d" . '/'
    ); // 作为 PHP 代码运行

    $replace = array("\n",
        "\"",
        "&",
        "<",
        ">",
        " ",
        chr(161),
        chr(162),
        chr(163),
        chr(169),
        chr(1),
        ''
    );
    return preg_replace($search, $replace, $str);
}

function waitforret()
{
    if ('exit' == inputstr()) return TRUE;
    return FALSE;
}

function inputstr()
{
    return trim(fgets(STDIN));
}
