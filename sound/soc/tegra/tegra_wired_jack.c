


<!DOCTYPE html>
<html>
  <head>
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="chrome=1">
        <title>sound/soc/tegra/tegra_wired_jack.c at c78df7de7ddf98215604a5a10a77b10eab10b9c2 from fards/kernel_2.6.36_nvidia_base - GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />

    
    

    <meta content="authenticity_token" name="csrf-param" />
<meta name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/stylesheets/bundles/github-ed04e8b8be3e88286d2fedb5ade5607df0599719.css" media="screen" rel="stylesheet" type="text/css" />
    

    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundles/jquery-0afaa9d8025004af7fc6f2a561837057d3f21298.js" type="text/javascript"></script>
    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundles/github-b1872f46a080aa92c45573ca095de24a21d5f9ff.js" type="text/javascript"></script>
    

      <link rel='permalink' href='/fards/kernel_2.6.36_nvidia_base/blob/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound/soc/tegra/tegra_wired_jack.c'>
    <META NAME="ROBOTS" CONTENT="NOINDEX, FOLLOW">

    <meta name="description" content="kernel_2.6.36_nvidia_base - Kernel based on Vegacomb - Adam for Gtablet" />
  <link href="https://github.com/fards/kernel_2.6.36_nvidia_base/commits/c78df7de7ddf98215604a5a10a77b10eab10b9c2.atom" rel="alternate" title="Recent Commits to kernel_2.6.36_nvidia_base:c78df7de7ddf98215604a5a10a77b10eab10b9c2" type="application/atom+xml" />

  </head>


  <body class="logged_out page-blob  env-production ">
    


    

    <div id="main">
      <div id="header" class="true">
          <a class="logo" href="https://github.com">
            <img alt="github" class="default svg" height="45" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov6.svg?1315937721" />
            <img alt="github" class="default png" height="45" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov6.png?1315937721" />
            <!--[if (gt IE 8)|!(IE)]><!-->
            <img alt="github" class="hover svg" height="45" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov6-hover.svg?1315937721" />
            <img alt="github" class="hover png" height="45" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov6-hover.png?1315937721" />
            <!--<![endif]-->
          </a>

        <div class="topsearch">
    <!--
      make sure to use fully qualified URLs here since this nav
      is used on error pages on other domains
    -->
    <ul class="nav logged_out">
        <li class="pricing"><a href="https://github.com/plans">Signup and Pricing</a></li>
        <li class="explore"><a href="https://github.com/explore">Explore GitHub</a></li>
      <li class="features"><a href="https://github.com/features">Features</a></li>
        <li class="blog"><a href="https://github.com/blog">Blog</a></li>
      <li class="login"><a href="https://github.com/login?return_to=%2Ffards%2Fkernel_2.6.36_nvidia_base%2Fblob%2Fc78df7de7ddf98215604a5a10a77b10eab10b9c2%2Fsound%2Fsoc%2Ftegra%2Ftegra_wired_jack.c">Login</a></li>
    </ul>
</div>

      </div>

      
            <div class="site">
      <div class="pagehead repohead vis-public fork  instapaper_ignore readability-menu">


      <div class="title-actions-bar">
        <h1>
          <a href="/fards">fards</a> /
          <strong><a href="/fards/kernel_2.6.36_nvidia_base" class="js-current-repository">kernel_2.6.36_nvidia_base</a></strong>
            <span class="fork-flag">
              <span class="text">forked from <a href="/treznorx/kernel_2.6.36_nvidia_base">treznorx/kernel_2.6.36_nvidia_base</a></span>
            </span>
        </h1>
        



            <ul class="pagehead-actions">

        <li class="js-toggler-container watch-button-container ">
          <a href="/fards/kernel_2.6.36_nvidia_base/toggle_watch" class="minibutton btn-watch watch-button js-toggler-target" data-method="post" data-remote="true"><span><span class="icon"></span>Watch</span></a>
          <a href="/fards/kernel_2.6.36_nvidia_base/toggle_watch" class="minibutton btn-watch unwatch-button js-toggler-target" data-method="post" data-remote="true"><span><span class="icon"></span>Unwatch</span></a>
        </li>
            <li><a href="/fards/kernel_2.6.36_nvidia_base/fork" class="minibutton btn-fork fork-button" data-method="post"><span><span class="icon"></span>Fork</span></a></li>

      <li class="repostats">
        <ul class="repo-stats">
          <li class="watchers ">
            <a href="/fards/kernel_2.6.36_nvidia_base/watchers" title="Watchers" class="tooltipped downwards">
              6
            </a>
          </li>
          <li class="forks">
            <a href="/fards/kernel_2.6.36_nvidia_base/network" title="Forks" class="tooltipped downwards">
              16
            </a>
          </li>
        </ul>
      </li>
    </ul>

      </div>

        

  <ul class="tabs">
    <li><a href="/fards/kernel_2.6.36_nvidia_base/tree/" class="selected" highlight="repo_sourcerepo_downloadsrepo_commitsrepo_tagsrepo_branches">Code</a></li>
    <li><a href="/fards/kernel_2.6.36_nvidia_base/network" highlight="repo_networkrepo_fork_queue">Network</a>
    <li><a href="/fards/kernel_2.6.36_nvidia_base/pulls" highlight="repo_pulls">Pull Requests <span class='counter'>0</span></a></li>



    <li><a href="/fards/kernel_2.6.36_nvidia_base/graphs" highlight="repo_graphsrepo_contributors">Stats &amp; Graphs</a></li>

  </ul>

  
<div class="frame frame-center tree-finder" style="display:none"
      data-tree-list-url="/fards/kernel_2.6.36_nvidia_base/tree-list/c78df7de7ddf98215604a5a10a77b10eab10b9c2"
      data-blob-url-prefix="/fards/kernel_2.6.36_nvidia_base/blob/c78df7de7ddf98215604a5a10a77b10eab10b9c2"
    >

  <div class="breadcrumb">
    <b><a href="/fards/kernel_2.6.36_nvidia_base">kernel_2.6.36_nvidia_base</a></b> /
    <input class="tree-finder-input" type="text" name="query" autocomplete="off" spellcheck="false">
  </div>

    <div class="octotip">
      <p>
        <a href="/fards/kernel_2.6.36_nvidia_base/dismiss-tree-finder-help" class="dismiss js-dismiss-tree-list-help" title="Hide this notice forever">Dismiss</a>
        <strong>Octotip:</strong> You've activated the <em>file finder</em>
        by pressing <span class="kbd">t</span> Start typing to filter the
        file list. Use <span class="kbd badmono">↑</span> and
        <span class="kbd badmono">↓</span> to navigate,
        <span class="kbd">enter</span> to view files.
      </p>
    </div>

  <table class="tree-browser" cellpadding="0" cellspacing="0">
    <tr class="js-header"><th>&nbsp;</th><th>name</th></tr>
    <tr class="js-no-results no-results" style="display: none">
      <th colspan="2">No matching files</th>
    </tr>
    <tbody class="js-results-list">
    </tbody>
  </table>
</div>

<div id="jump-to-line" style="display:none">
  <h2>Jump to Line</h2>
  <form>
    <input class="textfield" type="text">
    <div class="full-button">
      <button type="submit" class="classy">
        <span>Go</span>
      </button>
    </div>
  </form>
</div>


<div class="subnav-bar">

  <ul class="actions">
    
      <li class="switcher">

        <div class="context-menu-container js-menu-container">
          <span class="text">Current tree:</span>
          <a href="#"
             class="minibutton bigger switcher context-menu-button js-menu-target js-commitish-button btn-tree repo-tree"
             data-master-branch="dev-hc"
             data-ref="">
            <span><span class="icon"></span>c78df7de7d</span>
          </a>

          <div class="context-pane commitish-context js-menu-content">
            <a href="javascript:;" class="close js-menu-close"></a>
            <div class="title">Switch Branches/Tags</div>
            <div class="body pane-selector commitish-selector js-filterable-commitishes">
              <div class="filterbar">
                <div class="placeholder-field js-placeholder-field">
                  <label class="placeholder" for="context-commitish-filter-field" data-placeholder-mode="sticky">Filter branches/tags</label>
                  <input type="text" id="context-commitish-filter-field" class="commitish-filter" />
                </div>

                <ul class="tabs">
                  <li><a href="#" data-filter="branches" class="selected">Branches</a></li>
                  <li><a href="#" data-filter="tags">Tags</a></li>
                </ul>
              </div>

                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/fards/kernel_2.6.36_nvidia_base/blob/dev-hc/sound/soc/tegra/tegra_wired_jack.c" data-name="dev-hc">dev-hc</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/fards/kernel_2.6.36_nvidia_base/blob/nv-11.2.11/sound/soc/tegra/tegra_wired_jack.c" data-name="nv-11.2.11">nv-11.2.11</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/fards/kernel_2.6.36_nvidia_base/blob/nv-11.2.12/sound/soc/tegra/tegra_wired_jack.c" data-name="nv-11.2.12">nv-11.2.12</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/fards/kernel_2.6.36_nvidia_base/blob/nv-11.2.13/sound/soc/tegra/tegra_wired_jack.c" data-name="nv-11.2.13">nv-11.2.13</a>
                  </h4>
                </div>


              <div class="no-results" style="display:none">Nothing to show</div>
            </div>
          </div><!-- /.commitish-context-context -->
        </div>

      </li>
  </ul>

  <ul class="subnav">
    <li><a href="/fards/kernel_2.6.36_nvidia_base/tree/" class="selected" highlight="repo_source">Files</a></li>
    <li><a href="/fards/kernel_2.6.36_nvidia_base/commits/" highlight="repo_commits">Commits</a></li>
    <li><a href="/fards/kernel_2.6.36_nvidia_base/branches" class="" highlight="repo_branches">Branches <span class="counter">4</span></a></li>
    <li><a href="/fards/kernel_2.6.36_nvidia_base/tags" class="blank" highlight="repo_tags">Tags <span class="counter">0</span></a></li>
    <li><a href="/fards/kernel_2.6.36_nvidia_base/downloads" class="blank" highlight="repo_downloads">Downloads <span class="counter">0</span></a></li>
  </ul>

</div>

  
  
  


        

      </div><!-- /.pagehead -->

      




    <p class="last-commit locked">Browsing ref <tt>c78df7de7d</tt></p>

<div class="commit commit-tease js-details-container">
  <p class="commit-title ">
      <a href="/fards/kernel_2.6.36_nvidia_base/commit/c78df7de7ddf98215604a5a10a77b10eab10b9c2" class="message">Prepare for sound</a>
      
  </p>
  <div class="commit-meta">
    <a href="/fards/kernel_2.6.36_nvidia_base/commit/c78df7de7ddf98215604a5a10a77b10eab10b9c2" class="sha-block">commit <span class="sha">c78df7de7d</span></a>

    <div class="authorship">
      <img class="gravatar" height="20" src="https://secure.gravatar.com/avatar/afd34e31f781522eaf96ba6cd85725bd?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-140.png" width="20" />
      <span class="author-name"><a href="/treznorx">treznorx</a></span>
      authored <time class="js-relative-date" datetime="2011-09-24T22:15:37-07:00" title="2011-09-24 22:15:37">September 24, 2011</time>

    </div>
  </div>
</div>


  <div id="slider">

    <div class="breadcrumb" data-path="sound/soc/tegra/tegra_wired_jack.c/">
      <b><a href="/fards/kernel_2.6.36_nvidia_base/tree/c78df7de7ddf98215604a5a10a77b10eab10b9c2" class="js-rewrite-sha">kernel_2.6.36_nvidia_base</a></b> / <a href="/fards/kernel_2.6.36_nvidia_base/tree/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound" class="js-rewrite-sha">sound</a> / <a href="/fards/kernel_2.6.36_nvidia_base/tree/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound/soc" class="js-rewrite-sha">soc</a> / <a href="/fards/kernel_2.6.36_nvidia_base/tree/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound/soc/tegra" class="js-rewrite-sha">tegra</a> / tegra_wired_jack.c       <span style="display:none" id="clippy_1307" class="clippy-text">sound/soc/tegra/tegra_wired_jack.c</span>
      
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="110"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="https://a248.e.akamai.net/assets.github.com/flash/clippy.swf?1315928456?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=clippy_1307&amp;copied=copied!&amp;copyto=copy to clipboard">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="https://a248.e.akamai.net/assets.github.com/flash/clippy.swf?1315928456?v5"
             width="110"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=clippy_1307&amp;copied=copied!&amp;copyto=copy to clipboard"
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      

    </div>

    <div class="frames">
      <div class="frame frame-center" data-path="sound/soc/tegra/tegra_wired_jack.c/" data-permalink-url="/fards/kernel_2.6.36_nvidia_base/blob/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound/soc/tegra/tegra_wired_jack.c" data-title="sound/soc/tegra/tegra_wired_jack.c at c78df7de7ddf98215604a5a10a77b10eab10b9c2 from fards/kernel_2.6.36_nvidia_base - GitHub" data-type="blob">
          <ul class="big-actions">
            <li><a class="file-edit-link minibutton js-rewrite-sha" href="/fards/kernel_2.6.36_nvidia_base/edit/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound/soc/tegra/tegra_wired_jack.c" data-method="post"><span>Edit this file</span></a></li>
          </ul>

        <div id="files">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><img alt="Txt" height="16" src="https://a248.e.akamai.net/assets.github.com/images/icons/txt.png?1315928456" width="16" /></span>
                <span class="mode" title="File Mode">100644</span>
                  <span>375 lines (313 sloc)</span>
                <span>8.359 kb</span>
              </div>
              <ul class="actions">
                <li><a href="/fards/kernel_2.6.36_nvidia_base/raw/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound/soc/tegra/tegra_wired_jack.c" id="raw-url">raw</a></li>
                  <li><a href="/fards/kernel_2.6.36_nvidia_base/blame/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound/soc/tegra/tegra_wired_jack.c">blame</a></li>
                <li><a href="/fards/kernel_2.6.36_nvidia_base/commits/c78df7de7ddf98215604a5a10a77b10eab10b9c2/sound/soc/tegra/tegra_wired_jack.c" rel="nofollow">history</a></li>
              </ul>
            </div>
              <div class="data type-c">
      <table cellpadding="0" cellspacing="0" class="lines">
        <tr>
          <td>
            <pre class="line_numbers"><span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>
<span id="L194" rel="#L194">194</span>
<span id="L195" rel="#L195">195</span>
<span id="L196" rel="#L196">196</span>
<span id="L197" rel="#L197">197</span>
<span id="L198" rel="#L198">198</span>
<span id="L199" rel="#L199">199</span>
<span id="L200" rel="#L200">200</span>
<span id="L201" rel="#L201">201</span>
<span id="L202" rel="#L202">202</span>
<span id="L203" rel="#L203">203</span>
<span id="L204" rel="#L204">204</span>
<span id="L205" rel="#L205">205</span>
<span id="L206" rel="#L206">206</span>
<span id="L207" rel="#L207">207</span>
<span id="L208" rel="#L208">208</span>
<span id="L209" rel="#L209">209</span>
<span id="L210" rel="#L210">210</span>
<span id="L211" rel="#L211">211</span>
<span id="L212" rel="#L212">212</span>
<span id="L213" rel="#L213">213</span>
<span id="L214" rel="#L214">214</span>
<span id="L215" rel="#L215">215</span>
<span id="L216" rel="#L216">216</span>
<span id="L217" rel="#L217">217</span>
<span id="L218" rel="#L218">218</span>
<span id="L219" rel="#L219">219</span>
<span id="L220" rel="#L220">220</span>
<span id="L221" rel="#L221">221</span>
<span id="L222" rel="#L222">222</span>
<span id="L223" rel="#L223">223</span>
<span id="L224" rel="#L224">224</span>
<span id="L225" rel="#L225">225</span>
<span id="L226" rel="#L226">226</span>
<span id="L227" rel="#L227">227</span>
<span id="L228" rel="#L228">228</span>
<span id="L229" rel="#L229">229</span>
<span id="L230" rel="#L230">230</span>
<span id="L231" rel="#L231">231</span>
<span id="L232" rel="#L232">232</span>
<span id="L233" rel="#L233">233</span>
<span id="L234" rel="#L234">234</span>
<span id="L235" rel="#L235">235</span>
<span id="L236" rel="#L236">236</span>
<span id="L237" rel="#L237">237</span>
<span id="L238" rel="#L238">238</span>
<span id="L239" rel="#L239">239</span>
<span id="L240" rel="#L240">240</span>
<span id="L241" rel="#L241">241</span>
<span id="L242" rel="#L242">242</span>
<span id="L243" rel="#L243">243</span>
<span id="L244" rel="#L244">244</span>
<span id="L245" rel="#L245">245</span>
<span id="L246" rel="#L246">246</span>
<span id="L247" rel="#L247">247</span>
<span id="L248" rel="#L248">248</span>
<span id="L249" rel="#L249">249</span>
<span id="L250" rel="#L250">250</span>
<span id="L251" rel="#L251">251</span>
<span id="L252" rel="#L252">252</span>
<span id="L253" rel="#L253">253</span>
<span id="L254" rel="#L254">254</span>
<span id="L255" rel="#L255">255</span>
<span id="L256" rel="#L256">256</span>
<span id="L257" rel="#L257">257</span>
<span id="L258" rel="#L258">258</span>
<span id="L259" rel="#L259">259</span>
<span id="L260" rel="#L260">260</span>
<span id="L261" rel="#L261">261</span>
<span id="L262" rel="#L262">262</span>
<span id="L263" rel="#L263">263</span>
<span id="L264" rel="#L264">264</span>
<span id="L265" rel="#L265">265</span>
<span id="L266" rel="#L266">266</span>
<span id="L267" rel="#L267">267</span>
<span id="L268" rel="#L268">268</span>
<span id="L269" rel="#L269">269</span>
<span id="L270" rel="#L270">270</span>
<span id="L271" rel="#L271">271</span>
<span id="L272" rel="#L272">272</span>
<span id="L273" rel="#L273">273</span>
<span id="L274" rel="#L274">274</span>
<span id="L275" rel="#L275">275</span>
<span id="L276" rel="#L276">276</span>
<span id="L277" rel="#L277">277</span>
<span id="L278" rel="#L278">278</span>
<span id="L279" rel="#L279">279</span>
<span id="L280" rel="#L280">280</span>
<span id="L281" rel="#L281">281</span>
<span id="L282" rel="#L282">282</span>
<span id="L283" rel="#L283">283</span>
<span id="L284" rel="#L284">284</span>
<span id="L285" rel="#L285">285</span>
<span id="L286" rel="#L286">286</span>
<span id="L287" rel="#L287">287</span>
<span id="L288" rel="#L288">288</span>
<span id="L289" rel="#L289">289</span>
<span id="L290" rel="#L290">290</span>
<span id="L291" rel="#L291">291</span>
<span id="L292" rel="#L292">292</span>
<span id="L293" rel="#L293">293</span>
<span id="L294" rel="#L294">294</span>
<span id="L295" rel="#L295">295</span>
<span id="L296" rel="#L296">296</span>
<span id="L297" rel="#L297">297</span>
<span id="L298" rel="#L298">298</span>
<span id="L299" rel="#L299">299</span>
<span id="L300" rel="#L300">300</span>
<span id="L301" rel="#L301">301</span>
<span id="L302" rel="#L302">302</span>
<span id="L303" rel="#L303">303</span>
<span id="L304" rel="#L304">304</span>
<span id="L305" rel="#L305">305</span>
<span id="L306" rel="#L306">306</span>
<span id="L307" rel="#L307">307</span>
<span id="L308" rel="#L308">308</span>
<span id="L309" rel="#L309">309</span>
<span id="L310" rel="#L310">310</span>
<span id="L311" rel="#L311">311</span>
<span id="L312" rel="#L312">312</span>
<span id="L313" rel="#L313">313</span>
<span id="L314" rel="#L314">314</span>
<span id="L315" rel="#L315">315</span>
<span id="L316" rel="#L316">316</span>
<span id="L317" rel="#L317">317</span>
<span id="L318" rel="#L318">318</span>
<span id="L319" rel="#L319">319</span>
<span id="L320" rel="#L320">320</span>
<span id="L321" rel="#L321">321</span>
<span id="L322" rel="#L322">322</span>
<span id="L323" rel="#L323">323</span>
<span id="L324" rel="#L324">324</span>
<span id="L325" rel="#L325">325</span>
<span id="L326" rel="#L326">326</span>
<span id="L327" rel="#L327">327</span>
<span id="L328" rel="#L328">328</span>
<span id="L329" rel="#L329">329</span>
<span id="L330" rel="#L330">330</span>
<span id="L331" rel="#L331">331</span>
<span id="L332" rel="#L332">332</span>
<span id="L333" rel="#L333">333</span>
<span id="L334" rel="#L334">334</span>
<span id="L335" rel="#L335">335</span>
<span id="L336" rel="#L336">336</span>
<span id="L337" rel="#L337">337</span>
<span id="L338" rel="#L338">338</span>
<span id="L339" rel="#L339">339</span>
<span id="L340" rel="#L340">340</span>
<span id="L341" rel="#L341">341</span>
<span id="L342" rel="#L342">342</span>
<span id="L343" rel="#L343">343</span>
<span id="L344" rel="#L344">344</span>
<span id="L345" rel="#L345">345</span>
<span id="L346" rel="#L346">346</span>
<span id="L347" rel="#L347">347</span>
<span id="L348" rel="#L348">348</span>
<span id="L349" rel="#L349">349</span>
<span id="L350" rel="#L350">350</span>
<span id="L351" rel="#L351">351</span>
<span id="L352" rel="#L352">352</span>
<span id="L353" rel="#L353">353</span>
<span id="L354" rel="#L354">354</span>
<span id="L355" rel="#L355">355</span>
<span id="L356" rel="#L356">356</span>
<span id="L357" rel="#L357">357</span>
<span id="L358" rel="#L358">358</span>
<span id="L359" rel="#L359">359</span>
<span id="L360" rel="#L360">360</span>
<span id="L361" rel="#L361">361</span>
<span id="L362" rel="#L362">362</span>
<span id="L363" rel="#L363">363</span>
<span id="L364" rel="#L364">364</span>
<span id="L365" rel="#L365">365</span>
<span id="L366" rel="#L366">366</span>
<span id="L367" rel="#L367">367</span>
<span id="L368" rel="#L368">368</span>
<span id="L369" rel="#L369">369</span>
<span id="L370" rel="#L370">370</span>
<span id="L371" rel="#L371">371</span>
<span id="L372" rel="#L372">372</span>
<span id="L373" rel="#L373">373</span>
<span id="L374" rel="#L374">374</span>
<span id="L375" rel="#L375">375</span>
</pre>
          </td>
          <td width="100%">
                <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/*</span></div><div class='line' id='LC2'><span class="cm">* sound/soc/tegra/tegra_wired_jack.c</span></div><div class='line' id='LC3'><span class="cm">*</span></div><div class='line' id='LC4'><span class="cm">* Copyright (c) 2011, NVIDIA Corporation.</span></div><div class='line' id='LC5'><span class="cm">*</span></div><div class='line' id='LC6'><span class="cm">* This program is free software; you can redistribute it and/or modify</span></div><div class='line' id='LC7'><span class="cm">* it under the terms of the GNU General Public License as published by</span></div><div class='line' id='LC8'><span class="cm">* the Free Software Foundation; either version 2 of the License, or</span></div><div class='line' id='LC9'><span class="cm">* (at your option) any later version.</span></div><div class='line' id='LC10'><span class="cm">*</span></div><div class='line' id='LC11'><span class="cm">* This program is distributed in the hope that it will be useful, but WITHOUT</span></div><div class='line' id='LC12'><span class="cm">* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or</span></div><div class='line' id='LC13'><span class="cm">* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for</span></div><div class='line' id='LC14'><span class="cm">* more details.</span></div><div class='line' id='LC15'><span class="cm">*</span></div><div class='line' id='LC16'><span class="cm">* You should have received a copy of the GNU General Public License along</span></div><div class='line' id='LC17'><span class="cm">* with this program; if not, write to the Free Software Foundation, Inc.,</span></div><div class='line' id='LC18'><span class="cm">* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.</span></div><div class='line' id='LC19'><span class="cm">*/</span></div><div class='line' id='LC20'><br/></div><div class='line' id='LC21'><span class="cp">#include &lt;linux/types.h&gt;</span></div><div class='line' id='LC22'><span class="cp">#include &lt;linux/gpio.h&gt;</span></div><div class='line' id='LC23'><span class="cp">#ifdef CONFIG_SWITCH</span></div><div class='line' id='LC24'><span class="cp">#include &lt;linux/switch.h&gt;</span></div><div class='line' id='LC25'><span class="cp">#endif</span></div><div class='line' id='LC26'><span class="cp">#include &lt;linux/notifier.h&gt;</span></div><div class='line' id='LC27'><span class="cp">#include &lt;sound/jack.h&gt;</span></div><div class='line' id='LC28'><span class="cp">#include &lt;sound/soc.h&gt;</span></div><div class='line' id='LC29'><span class="cp">#include &lt;mach/audio.h&gt;</span></div><div class='line' id='LC30'><br/></div><div class='line' id='LC31'><span class="cp">#include &quot;tegra_soc.h&quot;</span></div><div class='line' id='LC32'><br/></div><div class='line' id='LC33'><span class="cp">#define HEAD_DET_GPIO 0</span></div><div class='line' id='LC34'><span class="cp">#define MIC_DET_GPIO 1</span></div><div class='line' id='LC35'><span class="cp">#define SPK_EN_GPIO 3</span></div><div class='line' id='LC36'><br/></div><div class='line' id='LC37'><span class="k">struct</span> <span class="n">wired_jack_conf</span> <span class="n">tegra_wired_jack_conf</span> <span class="o">=</span> <span class="p">{</span></div><div class='line' id='LC38'><span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="nb">NULL</span><span class="p">,</span> <span class="nb">NULL</span></div><div class='line' id='LC39'><span class="p">};</span></div><div class='line' id='LC40'><br/></div><div class='line' id='LC41'><span class="cm">/* Based on hp_gpio and mic_gpio, hp_gpio is active low */</span></div><div class='line' id='LC42'><span class="k">enum</span> <span class="p">{</span></div><div class='line' id='LC43'><span class="n">HEADSET_WITHOUT_MIC</span> <span class="o">=</span> <span class="mh">0x00</span><span class="p">,</span></div><div class='line' id='LC44'><span class="n">HEADSET_WITH_MIC</span> <span class="o">=</span> <span class="mh">0x01</span><span class="p">,</span></div><div class='line' id='LC45'><span class="n">NO_DEVICE</span> <span class="o">=</span> <span class="mh">0x10</span><span class="p">,</span></div><div class='line' id='LC46'><span class="n">MIC</span> <span class="o">=</span> <span class="mh">0x11</span><span class="p">,</span></div><div class='line' id='LC47'><span class="p">};</span></div><div class='line' id='LC48'><br/></div><div class='line' id='LC49'><span class="cm">/* These values are copied from WiredAccessoryObserver */</span></div><div class='line' id='LC50'><span class="k">enum</span> <span class="n">headset_state</span> <span class="p">{</span></div><div class='line' id='LC51'><span class="n">BIT_NO_HEADSET</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span></div><div class='line' id='LC52'><span class="n">BIT_HEADSET</span> <span class="o">=</span> <span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="mi">0</span><span class="p">),</span></div><div class='line' id='LC53'><span class="n">BIT_HEADSET_NO_MIC</span> <span class="o">=</span> <span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="mi">1</span><span class="p">),</span></div><div class='line' id='LC54'><span class="p">};</span></div><div class='line' id='LC55'><br/></div><div class='line' id='LC56'><span class="cm">/* jack */</span></div><div class='line' id='LC57'><span class="k">static</span> <span class="k">struct</span> <span class="n">snd_soc_jack</span> <span class="o">*</span><span class="n">tegra_wired_jack</span><span class="p">;</span></div><div class='line' id='LC58'><br/></div><div class='line' id='LC59'><span class="k">static</span> <span class="k">struct</span> <span class="n">snd_soc_jack_gpio</span> <span class="n">wired_jack_gpios</span><span class="p">[]</span> <span class="o">=</span> <span class="p">{</span></div><div class='line' id='LC60'><span class="p">{</span></div><div class='line' id='LC61'><span class="cm">/* gpio pin depends on board traits */</span></div><div class='line' id='LC62'><span class="p">.</span><span class="n">name</span> <span class="o">=</span> <span class="s">&quot;headphone-detect-gpio&quot;</span><span class="p">,</span></div><div class='line' id='LC63'><span class="p">.</span><span class="n">report</span> <span class="o">=</span> <span class="n">SND_JACK_HEADPHONE</span><span class="p">,</span></div><div class='line' id='LC64'><span class="p">.</span><span class="n">invert</span> <span class="o">=</span> <span class="mi">1</span><span class="p">,</span></div><div class='line' id='LC65'><span class="p">.</span><span class="n">debounce_time</span> <span class="o">=</span> <span class="mi">200</span><span class="p">,</span></div><div class='line' id='LC66'><span class="p">},</span></div><div class='line' id='LC67'><span class="p">{</span></div><div class='line' id='LC68'><span class="cm">/* gpio pin depens on board traits */</span></div><div class='line' id='LC69'><span class="p">.</span><span class="n">name</span> <span class="o">=</span> <span class="s">&quot;mic-detect-gpio&quot;</span><span class="p">,</span></div><div class='line' id='LC70'><span class="p">.</span><span class="n">report</span> <span class="o">=</span> <span class="n">SND_JACK_MICROPHONE</span><span class="p">,</span></div><div class='line' id='LC71'><span class="p">.</span><span class="n">invert</span> <span class="o">=</span> <span class="mi">1</span><span class="p">,</span></div><div class='line' id='LC72'><span class="p">.</span><span class="n">debounce_time</span> <span class="o">=</span> <span class="mi">200</span><span class="p">,</span></div><div class='line' id='LC73'><span class="p">},</span></div><div class='line' id='LC74'><span class="p">};</span></div><div class='line' id='LC75'><br/></div><div class='line' id='LC76'><span class="cp">#ifdef CONFIG_SWITCH</span></div><div class='line' id='LC77'><span class="k">static</span> <span class="k">struct</span> <span class="n">switch_dev</span> <span class="n">wired_switch_dev</span> <span class="o">=</span> <span class="p">{</span></div><div class='line' id='LC78'><span class="p">.</span><span class="n">name</span> <span class="o">=</span> <span class="s">&quot;h2w&quot;</span><span class="p">,</span></div><div class='line' id='LC79'><span class="p">};</span></div><div class='line' id='LC80'><br/></div><div class='line' id='LC81'><span class="kt">void</span> <span class="nf">tegra_switch_set_state</span><span class="p">(</span><span class="kt">int</span> <span class="n">state</span><span class="p">)</span></div><div class='line' id='LC82'><span class="p">{</span></div><div class='line' id='LC83'><span class="n">switch_set_state</span><span class="p">(</span><span class="o">&amp;</span><span class="n">wired_switch_dev</span><span class="p">,</span> <span class="n">state</span><span class="p">);</span></div><div class='line' id='LC84'><span class="p">}</span></div><div class='line' id='LC85'><br/></div><div class='line' id='LC86'><span class="k">static</span> <span class="k">enum</span> <span class="n">headset_state</span> <span class="nf">get_headset_state</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span></div><div class='line' id='LC87'><span class="p">{</span></div><div class='line' id='LC88'><span class="k">enum</span> <span class="n">headset_state</span> <span class="n">state</span> <span class="o">=</span> <span class="n">BIT_NO_HEADSET</span><span class="p">;</span></div><div class='line' id='LC89'><span class="kt">int</span> <span class="n">flag</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC90'><span class="kt">int</span> <span class="n">hp_gpio</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC91'><span class="kt">int</span> <span class="n">mic_gpio</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC92'><br/></div><div class='line' id='LC93'><span class="cm">/* hp_det_n is low active pin */</span></div><div class='line' id='LC94'><span class="k">if</span> <span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">hp_det_n</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC95'><span class="n">hp_gpio</span> <span class="o">=</span> <span class="n">gpio_get_value</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">hp_det_n</span><span class="p">);</span></div><div class='line' id='LC96'><span class="k">if</span> <span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">cdc_irq</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC97'><span class="n">mic_gpio</span> <span class="o">=</span> <span class="n">gpio_get_value</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">cdc_irq</span><span class="p">);</span></div><div class='line' id='LC98'><br/></div><div class='line' id='LC99'><span class="n">pr_debug</span><span class="p">(</span><span class="s">&quot;hp_gpio:%d, mic_gpio:%d</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span> <span class="n">hp_gpio</span><span class="p">,</span> <span class="n">mic_gpio</span><span class="p">);</span></div><div class='line' id='LC100'><br/></div><div class='line' id='LC101'><span class="n">flag</span> <span class="o">=</span> <span class="p">(</span><span class="n">hp_gpio</span> <span class="o">&lt;&lt;</span> <span class="mi">4</span><span class="p">)</span> <span class="o">|</span> <span class="n">mic_gpio</span><span class="p">;</span></div><div class='line' id='LC102'><br/></div><div class='line' id='LC103'><span class="k">switch</span> <span class="p">(</span><span class="n">flag</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC104'><span class="k">case</span> <span class="n">NO_DEVICE</span>:</div><div class='line' id='LC105'><span class="n">state</span> <span class="o">=</span> <span class="n">BIT_NO_HEADSET</span><span class="p">;</span></div><div class='line' id='LC106'><span class="k">break</span><span class="p">;</span></div><div class='line' id='LC107'><span class="k">case</span> <span class="n">HEADSET_WITH_MIC</span>:</div><div class='line' id='LC108'><span class="n">state</span> <span class="o">=</span> <span class="n">BIT_HEADSET</span><span class="p">;</span></div><div class='line' id='LC109'><span class="k">break</span><span class="p">;</span></div><div class='line' id='LC110'><span class="k">case</span> <span class="n">MIC</span>:</div><div class='line' id='LC111'><span class="cm">/* mic: would not report */</span></div><div class='line' id='LC112'><span class="k">break</span><span class="p">;</span></div><div class='line' id='LC113'><span class="k">case</span> <span class="n">HEADSET_WITHOUT_MIC</span>:</div><div class='line' id='LC114'><span class="n">state</span> <span class="o">=</span> <span class="n">BIT_HEADSET_NO_MIC</span><span class="p">;</span></div><div class='line' id='LC115'><span class="k">break</span><span class="p">;</span></div><div class='line' id='LC116'><span class="nl">default:</span></div><div class='line' id='LC117'><span class="n">state</span> <span class="o">=</span> <span class="n">BIT_NO_HEADSET</span><span class="p">;</span></div><div class='line' id='LC118'><span class="p">}</span></div><div class='line' id='LC119'><br/></div><div class='line' id='LC120'><span class="k">return</span> <span class="n">state</span><span class="p">;</span></div><div class='line' id='LC121'><span class="p">}</span></div><div class='line' id='LC122'><br/></div><div class='line' id='LC123'><span class="k">static</span> <span class="kt">int</span> <span class="nf">wired_switch_notify</span><span class="p">(</span><span class="k">struct</span> <span class="n">notifier_block</span> <span class="o">*</span><span class="n">self</span><span class="p">,</span></div><div class='line' id='LC124'><span class="kt">unsigned</span> <span class="kt">long</span> <span class="n">action</span><span class="p">,</span> <span class="kt">void</span><span class="o">*</span> <span class="n">dev</span><span class="p">)</span></div><div class='line' id='LC125'><span class="p">{</span></div><div class='line' id='LC126'><span class="n">tegra_switch_set_state</span><span class="p">(</span><span class="n">get_headset_state</span><span class="p">());</span></div><div class='line' id='LC127'><br/></div><div class='line' id='LC128'><span class="k">return</span> <span class="n">NOTIFY_OK</span><span class="p">;</span></div><div class='line' id='LC129'><span class="p">}</span></div><div class='line' id='LC130'><br/></div><div class='line' id='LC131'><span class="kt">void</span> <span class="nf">tegra_jack_suspend</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span></div><div class='line' id='LC132'><span class="p">{</span></div><div class='line' id='LC133'><span class="kt">int</span> <span class="n">i</span><span class="p">;</span></div><div class='line' id='LC134'><br/></div><div class='line' id='LC135'><span class="k">for</span> <span class="p">(</span><span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">ARRAY_SIZE</span><span class="p">(</span><span class="n">wired_jack_gpios</span><span class="p">);</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span></div><div class='line' id='LC136'><span class="n">disable_irq</span><span class="p">(</span><span class="n">gpio_to_irq</span><span class="p">(</span><span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">gpio</span><span class="p">));</span></div><div class='line' id='LC137'><span class="p">}</span></div><div class='line' id='LC138'><br/></div><div class='line' id='LC139'><span class="kt">void</span> <span class="nf">tegra_jack_resume</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span></div><div class='line' id='LC140'><span class="p">{</span></div><div class='line' id='LC141'><span class="kt">int</span> <span class="n">i</span><span class="p">,</span> <span class="n">val</span><span class="p">;</span></div><div class='line' id='LC142'><br/></div><div class='line' id='LC143'><span class="k">for</span> <span class="p">(</span><span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">ARRAY_SIZE</span><span class="p">(</span><span class="n">wired_jack_gpios</span><span class="p">);</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC144'><span class="n">val</span> <span class="o">=</span> <span class="n">gpio_get_value</span><span class="p">(</span><span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">gpio</span><span class="p">);</span></div><div class='line' id='LC145'><span class="n">val</span> <span class="o">=</span> <span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">invert</span> <span class="o">?</span> <span class="o">!</span><span class="n">val</span> <span class="o">:</span> <span class="n">val</span><span class="p">;</span></div><div class='line' id='LC146'><span class="n">val</span> <span class="o">=</span> <span class="n">val</span> <span class="o">?</span> <span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">report</span> <span class="o">:</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC147'><br/></div><div class='line' id='LC148'><span class="n">snd_soc_jack_report</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">,</span> <span class="n">val</span><span class="p">,</span></div><div class='line' id='LC149'><span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">report</span><span class="p">);</span></div><div class='line' id='LC150'><br/></div><div class='line' id='LC151'><span class="n">enable_irq</span><span class="p">(</span><span class="n">gpio_to_irq</span><span class="p">(</span><span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">gpio</span><span class="p">));</span></div><div class='line' id='LC152'><span class="p">}</span></div><div class='line' id='LC153'><span class="p">}</span></div><div class='line' id='LC154'><br/></div><div class='line' id='LC155'><span class="k">static</span> <span class="k">struct</span> <span class="n">notifier_block</span> <span class="n">wired_switch_nb</span> <span class="o">=</span> <span class="p">{</span></div><div class='line' id='LC156'><span class="p">.</span><span class="n">notifier_call</span> <span class="o">=</span> <span class="n">wired_switch_notify</span><span class="p">,</span></div><div class='line' id='LC157'><span class="p">};</span></div><div class='line' id='LC158'><span class="cp">#endif</span></div><div class='line' id='LC159'><br/></div><div class='line' id='LC160'><span class="cm">/* platform driver */</span></div><div class='line' id='LC161'><span class="k">static</span> <span class="kt">int</span> <span class="nf">tegra_wired_jack_probe</span><span class="p">(</span><span class="k">struct</span> <span class="n">platform_device</span> <span class="o">*</span><span class="n">pdev</span><span class="p">)</span></div><div class='line' id='LC162'><span class="p">{</span></div><div class='line' id='LC163'><span class="kt">int</span> <span class="n">ret</span><span class="p">;</span></div><div class='line' id='LC164'><span class="kt">int</span> <span class="n">hp_det_n</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">cdc_irq</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC165'><span class="kt">int</span> <span class="n">en_mic_int</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="n">en_mic_ext</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC166'><span class="kt">int</span> <span class="n">en_spkr</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC167'><span class="k">struct</span> <span class="n">wired_jack_conf</span> <span class="o">*</span><span class="n">pdata</span><span class="p">;</span></div><div class='line' id='LC168'><br/></div><div class='line' id='LC169'><span class="n">pdata</span> <span class="o">=</span> <span class="p">(</span><span class="k">struct</span> <span class="n">wired_jack_conf</span> <span class="o">*</span><span class="p">)</span><span class="n">pdev</span><span class="o">-&gt;</span><span class="n">dev</span><span class="p">.</span><span class="n">platform_data</span><span class="p">;</span></div><div class='line' id='LC170'><br/></div><div class='line' id='LC171'><span class="n">WARN_ON</span><span class="p">(</span><span class="o">!</span><span class="n">pdata</span><span class="p">);</span></div><div class='line' id='LC172'><br/></div><div class='line' id='LC173'><span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">pdata</span> <span class="o">||</span> <span class="o">!</span><span class="n">pdata</span><span class="o">-&gt;</span><span class="n">hp_det_n</span></div><div class='line' id='LC174'><span class="cp">#if defined(CONFIG_ARCH_TEGRA_2x_SOC)</span></div><div class='line' id='LC175'><span class="o">||</span> <span class="o">!</span><span class="n">pdata</span><span class="o">-&gt;</span><span class="n">en_mic_int</span> <span class="o">||</span> <span class="o">!</span><span class="n">pdata</span><span class="o">-&gt;</span><span class="n">en_mic_ext</span></div><div class='line' id='LC176'><span class="cp">#endif</span></div><div class='line' id='LC177'><span class="o">||</span> <span class="o">!</span><span class="n">pdata</span><span class="o">-&gt;</span><span class="n">cdc_irq</span> <span class="o">||</span> <span class="o">!</span><span class="n">pdata</span><span class="o">-&gt;</span><span class="n">en_spkr</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC178'><span class="n">pr_err</span><span class="p">(</span><span class="s">&quot;Please set up gpio pins for jack.</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC179'><span class="k">return</span> <span class="o">-</span><span class="n">EBUSY</span><span class="p">;</span></div><div class='line' id='LC180'><span class="p">}</span></div><div class='line' id='LC181'><br/></div><div class='line' id='LC182'><span class="n">hp_det_n</span> <span class="o">=</span> <span class="n">pdata</span><span class="o">-&gt;</span><span class="n">hp_det_n</span><span class="p">;</span></div><div class='line' id='LC183'><span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">HEAD_DET_GPIO</span><span class="p">].</span><span class="n">gpio</span> <span class="o">=</span> <span class="n">hp_det_n</span><span class="p">;</span></div><div class='line' id='LC184'><br/></div><div class='line' id='LC185'><span class="n">ret</span> <span class="o">=</span> <span class="n">snd_soc_jack_add_gpios</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">,</span></div><div class='line' id='LC186'><span class="mi">1</span><span class="p">,</span></div><div class='line' id='LC187'><span class="o">&amp;</span><span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">HEAD_DET_GPIO</span><span class="p">]);</span></div><div class='line' id='LC188'><span class="k">if</span> <span class="p">(</span><span class="n">ret</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC189'><span class="n">pr_err</span><span class="p">(</span><span class="s">&quot;Could NOT set up gpio pins for hp jack.</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC190'><span class="n">snd_soc_jack_free_gpios</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">,</span></div><div class='line' id='LC191'><span class="n">ARRAY_SIZE</span><span class="p">(</span><span class="n">wired_jack_gpios</span><span class="p">),</span></div><div class='line' id='LC192'><span class="n">wired_jack_gpios</span><span class="p">);</span></div><div class='line' id='LC193'><span class="k">return</span> <span class="n">ret</span><span class="p">;</span></div><div class='line' id='LC194'><span class="p">}</span></div><div class='line' id='LC195'><br/></div><div class='line' id='LC196'><span class="n">cdc_irq</span> <span class="o">=</span> <span class="n">pdata</span><span class="o">-&gt;</span><span class="n">cdc_irq</span><span class="p">;</span></div><div class='line' id='LC197'><span class="k">if</span><span class="p">(</span><span class="n">cdc_irq</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">){</span></div><div class='line' id='LC198'><span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">MIC_DET_GPIO</span><span class="p">].</span><span class="n">gpio</span> <span class="o">=</span> <span class="n">cdc_irq</span><span class="p">;</span></div><div class='line' id='LC199'><br/></div><div class='line' id='LC200'><span class="n">ret</span> <span class="o">=</span> <span class="n">snd_soc_jack_add_gpios</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">,</span></div><div class='line' id='LC201'><span class="mi">1</span><span class="p">,</span></div><div class='line' id='LC202'><span class="o">&amp;</span><span class="n">wired_jack_gpios</span><span class="p">[</span><span class="n">MIC_DET_GPIO</span><span class="p">]);</span></div><div class='line' id='LC203'><span class="k">if</span> <span class="p">(</span><span class="n">ret</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC204'><span class="n">pr_err</span><span class="p">(</span><span class="s">&quot;Could NOT set up gpio pins for mic jack.</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC205'><span class="n">snd_soc_jack_free_gpios</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">,</span></div><div class='line' id='LC206'><span class="n">ARRAY_SIZE</span><span class="p">(</span><span class="n">wired_jack_gpios</span><span class="p">),</span></div><div class='line' id='LC207'><span class="n">wired_jack_gpios</span><span class="p">);</span></div><div class='line' id='LC208'><span class="k">return</span> <span class="n">ret</span><span class="p">;</span></div><div class='line' id='LC209'><span class="p">}</span></div><div class='line' id='LC210'><span class="p">}</span></div><div class='line' id='LC211'><br/></div><div class='line' id='LC212'><span class="cp">#if defined(CONFIG_ARCH_TEGRA_2x_SOC)</span></div><div class='line' id='LC213'><span class="cm">/* Mic switch controlling pins */</span></div><div class='line' id='LC214'><br/></div><div class='line' id='LC215'><span class="n">en_mic_int</span> <span class="o">=</span> <span class="n">pdata</span><span class="o">-&gt;</span><span class="n">en_mic_int</span><span class="p">;</span></div><div class='line' id='LC216'><span class="k">if</span><span class="p">(</span><span class="n">en_mic_int</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC217'><span class="p">{</span></div><div class='line' id='LC218'><span class="n">ret</span> <span class="o">=</span> <span class="n">gpio_request</span><span class="p">(</span><span class="n">en_mic_int</span><span class="p">,</span> <span class="s">&quot;en_mic_int&quot;</span><span class="p">);</span></div><div class='line' id='LC219'><span class="k">if</span> <span class="p">(</span><span class="n">ret</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC220'><span class="n">pr_err</span><span class="p">(</span><span class="s">&quot;Could NOT get gpio for internal mic controlling.</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC221'><span class="n">gpio_free</span><span class="p">(</span><span class="n">en_mic_int</span><span class="p">);</span></div><div class='line' id='LC222'><span class="n">en_mic_int</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC223'><span class="p">}</span></div><div class='line' id='LC224'><br/></div><div class='line' id='LC225'><span class="k">if</span> <span class="p">(</span><span class="n">en_mic_int</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC226'><span class="n">gpio_direction_output</span><span class="p">(</span><span class="n">en_mic_int</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC227'><span class="n">gpio_export</span><span class="p">(</span><span class="n">en_mic_int</span><span class="p">,</span> <span class="nb">false</span><span class="p">);</span></div><div class='line' id='LC228'><span class="p">}</span></div><div class='line' id='LC229'><span class="p">}</span></div><div class='line' id='LC230'><br/></div><div class='line' id='LC231'><span class="n">en_mic_ext</span> <span class="o">=</span> <span class="n">pdata</span><span class="o">-&gt;</span><span class="n">en_mic_ext</span><span class="p">;</span></div><div class='line' id='LC232'><span class="k">if</span><span class="p">(</span><span class="n">en_mic_ext</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC233'><span class="p">{</span></div><div class='line' id='LC234'><span class="n">ret</span> <span class="o">=</span> <span class="n">gpio_request</span><span class="p">(</span><span class="n">en_mic_ext</span><span class="p">,</span> <span class="s">&quot;en_mic_ext&quot;</span><span class="p">);</span></div><div class='line' id='LC235'><span class="k">if</span> <span class="p">(</span><span class="n">ret</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC236'><span class="n">pr_err</span><span class="p">(</span><span class="s">&quot;Could NOT get gpio for external mic controlling.</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC237'><span class="n">gpio_free</span><span class="p">(</span><span class="n">en_mic_ext</span><span class="p">);</span></div><div class='line' id='LC238'><span class="n">en_mic_ext</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC239'><span class="p">}</span></div><div class='line' id='LC240'><br/></div><div class='line' id='LC241'><span class="k">if</span> <span class="p">(</span><span class="n">en_mic_ext</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC242'><span class="n">gpio_direction_output</span><span class="p">(</span><span class="n">en_mic_ext</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC243'><span class="n">gpio_export</span><span class="p">(</span><span class="n">en_mic_ext</span><span class="p">,</span> <span class="nb">false</span><span class="p">);</span></div><div class='line' id='LC244'><span class="p">}</span></div><div class='line' id='LC245'><span class="p">}</span></div><div class='line' id='LC246'><br/></div><div class='line' id='LC247'><span class="cp">#endif</span></div><div class='line' id='LC248'><br/></div><div class='line' id='LC249'><span class="n">en_spkr</span> <span class="o">=</span> <span class="n">pdata</span><span class="o">-&gt;</span><span class="n">en_spkr</span><span class="p">;</span></div><div class='line' id='LC250'><span class="n">ret</span> <span class="o">=</span> <span class="n">gpio_request</span><span class="p">(</span><span class="n">en_spkr</span><span class="p">,</span> <span class="s">&quot;en_spkr&quot;</span><span class="p">);</span></div><div class='line' id='LC251'><span class="k">if</span> <span class="p">(</span><span class="n">ret</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC252'><span class="n">pr_err</span><span class="p">(</span><span class="s">&quot;Could NOT set up gpio pin for amplifier.</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC253'><span class="n">gpio_free</span><span class="p">(</span><span class="n">en_spkr</span><span class="p">);</span></div><div class='line' id='LC254'><span class="n">en_spkr</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC255'><span class="p">}</span></div><div class='line' id='LC256'><br/></div><div class='line' id='LC257'><br/></div><div class='line' id='LC258'><span class="k">if</span> <span class="p">(</span><span class="n">en_spkr</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC259'><span class="n">gpio_direction_output</span><span class="p">(</span><span class="n">en_spkr</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC260'><span class="n">gpio_export</span><span class="p">(</span><span class="n">en_spkr</span><span class="p">,</span> <span class="nb">false</span><span class="p">);</span></div><div class='line' id='LC261'><span class="p">}</span></div><div class='line' id='LC262'><br/></div><div class='line' id='LC263'><span class="k">if</span> <span class="p">(</span><span class="n">pdata</span><span class="o">-&gt;</span><span class="n">spkr_amp_reg</span><span class="p">)</span></div><div class='line' id='LC264'><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">amp_reg</span> <span class="o">=</span></div><div class='line' id='LC265'><span class="n">regulator_get</span><span class="p">(</span><span class="nb">NULL</span><span class="p">,</span> <span class="n">pdata</span><span class="o">-&gt;</span><span class="n">spkr_amp_reg</span><span class="p">);</span></div><div class='line' id='LC266'><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">amp_reg_enabled</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC267'><br/></div><div class='line' id='LC268'><span class="cm">/* restore configuration of these pins */</span></div><div class='line' id='LC269'><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">hp_det_n</span> <span class="o">=</span> <span class="n">hp_det_n</span><span class="p">;</span></div><div class='line' id='LC270'><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">en_mic_int</span> <span class="o">=</span> <span class="n">en_mic_int</span><span class="p">;</span></div><div class='line' id='LC271'><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">en_mic_ext</span> <span class="o">=</span> <span class="n">en_mic_ext</span><span class="p">;</span></div><div class='line' id='LC272'><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">cdc_irq</span> <span class="o">=</span> <span class="n">cdc_irq</span><span class="p">;</span></div><div class='line' id='LC273'><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">en_spkr</span> <span class="o">=</span> <span class="n">en_spkr</span><span class="p">;</span></div><div class='line' id='LC274'><br/></div><div class='line' id='LC275'><span class="c1">// Communicate the jack connection state at device bootup</span></div><div class='line' id='LC276'><span class="n">tegra_switch_set_state</span><span class="p">(</span><span class="n">get_headset_state</span><span class="p">());</span></div><div class='line' id='LC277'><br/></div><div class='line' id='LC278'><span class="cp">#ifdef CONFIG_SWITCH</span></div><div class='line' id='LC279'><span class="n">snd_soc_jack_notifier_register</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">,</span></div><div class='line' id='LC280'><span class="o">&amp;</span><span class="n">wired_switch_nb</span><span class="p">);</span></div><div class='line' id='LC281'><span class="cp">#endif</span></div><div class='line' id='LC282'><span class="k">return</span> <span class="n">ret</span><span class="p">;</span></div><div class='line' id='LC283'><span class="p">}</span></div><div class='line' id='LC284'><br/></div><div class='line' id='LC285'><span class="k">static</span> <span class="kt">int</span> <span class="nf">tegra_wired_jack_remove</span><span class="p">(</span><span class="k">struct</span> <span class="n">platform_device</span> <span class="o">*</span><span class="n">pdev</span><span class="p">)</span></div><div class='line' id='LC286'><span class="p">{</span></div><div class='line' id='LC287'><span class="n">snd_soc_jack_free_gpios</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">,</span></div><div class='line' id='LC288'><span class="n">ARRAY_SIZE</span><span class="p">(</span><span class="n">wired_jack_gpios</span><span class="p">),</span></div><div class='line' id='LC289'><span class="n">wired_jack_gpios</span><span class="p">);</span></div><div class='line' id='LC290'><br/></div><div class='line' id='LC291'><span class="k">if</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">en_mic_int</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC292'><span class="n">gpio_free</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">en_mic_int</span><span class="p">);</span></div><div class='line' id='LC293'><span class="k">if</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">en_mic_ext</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC294'><span class="n">gpio_free</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">en_mic_ext</span><span class="p">);</span></div><div class='line' id='LC295'><span class="n">gpio_free</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">en_spkr</span><span class="p">);</span></div><div class='line' id='LC296'><span class="k">if</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">cdc_irq</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC297'><span class="n">gpio_free</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">cdc_irq</span><span class="p">);</span></div><div class='line' id='LC298'><br/></div><div class='line' id='LC299'><span class="k">if</span> <span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">amp_reg</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC300'><span class="k">if</span> <span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">amp_reg_enabled</span><span class="p">)</span></div><div class='line' id='LC301'><span class="n">regulator_disable</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">amp_reg</span><span class="p">);</span></div><div class='line' id='LC302'><span class="n">regulator_put</span><span class="p">(</span><span class="n">tegra_wired_jack_conf</span><span class="p">.</span><span class="n">amp_reg</span><span class="p">);</span></div><div class='line' id='LC303'><span class="p">}</span></div><div class='line' id='LC304'><br/></div><div class='line' id='LC305'><span class="k">return</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC306'><span class="p">}</span></div><div class='line' id='LC307'><br/></div><div class='line' id='LC308'><span class="k">static</span> <span class="k">struct</span> <span class="n">platform_driver</span> <span class="n">tegra_wired_jack_driver</span> <span class="o">=</span> <span class="p">{</span></div><div class='line' id='LC309'><span class="p">.</span><span class="n">probe</span> <span class="o">=</span> <span class="n">tegra_wired_jack_probe</span><span class="p">,</span></div><div class='line' id='LC310'><span class="p">.</span><span class="n">remove</span> <span class="o">=</span> <span class="n">tegra_wired_jack_remove</span><span class="p">,</span></div><div class='line' id='LC311'><span class="p">.</span><span class="n">driver</span> <span class="o">=</span> <span class="p">{</span></div><div class='line' id='LC312'><span class="p">.</span><span class="n">name</span> <span class="o">=</span> <span class="s">&quot;tegra_wired_jack&quot;</span><span class="p">,</span></div><div class='line' id='LC313'><span class="p">.</span><span class="n">owner</span> <span class="o">=</span> <span class="n">THIS_MODULE</span><span class="p">,</span></div><div class='line' id='LC314'><span class="p">},</span></div><div class='line' id='LC315'><span class="p">};</span></div><div class='line' id='LC316'><br/></div><div class='line' id='LC317'><br/></div><div class='line' id='LC318'><span class="kt">int</span> <span class="nf">tegra_jack_init</span><span class="p">(</span><span class="k">struct</span> <span class="n">snd_soc_codec</span> <span class="o">*</span><span class="n">codec</span><span class="p">)</span></div><div class='line' id='LC319'><span class="p">{</span></div><div class='line' id='LC320'><span class="kt">int</span> <span class="n">ret</span><span class="p">;</span></div><div class='line' id='LC321'><br/></div><div class='line' id='LC322'><span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">codec</span><span class="p">)</span></div><div class='line' id='LC323'><span class="k">return</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC324'><br/></div><div class='line' id='LC325'><span class="n">tegra_wired_jack</span> <span class="o">=</span> <span class="n">kzalloc</span><span class="p">(</span><span class="k">sizeof</span><span class="p">(</span><span class="o">*</span><span class="n">tegra_wired_jack</span><span class="p">),</span> <span class="n">GFP_KERNEL</span><span class="p">);</span></div><div class='line' id='LC326'><span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">tegra_wired_jack</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC327'><span class="n">pr_err</span><span class="p">(</span><span class="s">&quot;failed to allocate tegra_wired_jack </span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC328'><span class="k">return</span> <span class="o">-</span><span class="n">ENOMEM</span><span class="p">;</span></div><div class='line' id='LC329'><span class="p">}</span></div><div class='line' id='LC330'><br/></div><div class='line' id='LC331'><span class="cm">/* Add jack detection */</span></div><div class='line' id='LC332'><span class="n">ret</span> <span class="o">=</span> <span class="n">snd_soc_jack_new</span><span class="p">(</span><span class="n">codec</span><span class="o">-&gt;</span><span class="n">socdev</span><span class="o">-&gt;</span><span class="n">card</span><span class="p">,</span> <span class="s">&quot;Wired Accessory Jack&quot;</span><span class="p">,</span></div><div class='line' id='LC333'><span class="n">SND_JACK_HEADSET</span><span class="p">,</span> <span class="n">tegra_wired_jack</span><span class="p">);</span></div><div class='line' id='LC334'><span class="k">if</span> <span class="p">(</span><span class="n">ret</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC335'><span class="k">goto</span> <span class="n">failed</span><span class="p">;</span></div><div class='line' id='LC336'><br/></div><div class='line' id='LC337'><span class="cp">#ifdef CONFIG_SWITCH</span></div><div class='line' id='LC338'><span class="cm">/* Addd h2w swith class support */</span></div><div class='line' id='LC339'><span class="n">ret</span> <span class="o">=</span> <span class="n">switch_dev_register</span><span class="p">(</span><span class="o">&amp;</span><span class="n">wired_switch_dev</span><span class="p">);</span></div><div class='line' id='LC340'><span class="k">if</span> <span class="p">(</span><span class="n">ret</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC341'><span class="k">goto</span> <span class="n">switch_dev_failed</span><span class="p">;</span></div><div class='line' id='LC342'><span class="cp">#endif</span></div><div class='line' id='LC343'><br/></div><div class='line' id='LC344'><span class="n">ret</span> <span class="o">=</span> <span class="n">platform_driver_register</span><span class="p">(</span><span class="o">&amp;</span><span class="n">tegra_wired_jack_driver</span><span class="p">);</span></div><div class='line' id='LC345'><span class="k">if</span> <span class="p">(</span><span class="n">ret</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC346'><span class="k">goto</span> <span class="n">platform_dev_failed</span><span class="p">;</span></div><div class='line' id='LC347'><br/></div><div class='line' id='LC348'><span class="k">return</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC349'><br/></div><div class='line' id='LC350'><span class="cp">#ifdef CONFIG_SWITCH</span></div><div class='line' id='LC351'><span class="nl">switch_dev_failed:</span></div><div class='line' id='LC352'><span class="n">switch_dev_unregister</span><span class="p">(</span><span class="o">&amp;</span><span class="n">wired_switch_dev</span><span class="p">);</span></div><div class='line' id='LC353'><span class="cp">#endif</span></div><div class='line' id='LC354'><span class="nl">platform_dev_failed:</span></div><div class='line' id='LC355'><span class="n">platform_driver_unregister</span><span class="p">(</span><span class="o">&amp;</span><span class="n">tegra_wired_jack_driver</span><span class="p">);</span></div><div class='line' id='LC356'><span class="nl">failed:</span></div><div class='line' id='LC357'><span class="k">if</span> <span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC358'><span class="n">kfree</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">);</span></div><div class='line' id='LC359'><span class="n">tegra_wired_jack</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC360'><span class="p">}</span></div><div class='line' id='LC361'><span class="k">return</span> <span class="n">ret</span><span class="p">;</span></div><div class='line' id='LC362'><span class="p">}</span></div><div class='line' id='LC363'><br/></div><div class='line' id='LC364'><span class="kt">void</span> <span class="nf">tegra_jack_exit</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span></div><div class='line' id='LC365'><span class="p">{</span></div><div class='line' id='LC366'><span class="cp">#ifdef CONFIG_SWITCH</span></div><div class='line' id='LC367'><span class="n">switch_dev_unregister</span><span class="p">(</span><span class="o">&amp;</span><span class="n">wired_switch_dev</span><span class="p">);</span></div><div class='line' id='LC368'><span class="cp">#endif</span></div><div class='line' id='LC369'><span class="n">platform_driver_unregister</span><span class="p">(</span><span class="o">&amp;</span><span class="n">tegra_wired_jack_driver</span><span class="p">);</span></div><div class='line' id='LC370'><br/></div><div class='line' id='LC371'><span class="k">if</span> <span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC372'><span class="n">kfree</span><span class="p">(</span><span class="n">tegra_wired_jack</span><span class="p">);</span></div><div class='line' id='LC373'><span class="n">tegra_wired_jack</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC374'><span class="p">}</span></div><div class='line' id='LC375'><span class="p">}</span></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>
      </div>
    </div>

  </div>

<div class="frame frame-loading" style="display:none;" data-tree-list-url="/fards/kernel_2.6.36_nvidia_base/tree-list/c78df7de7ddf98215604a5a10a77b10eab10b9c2" data-blob-url-prefix="/fards/kernel_2.6.36_nvidia_base/blob/c78df7de7ddf98215604a5a10a77b10eab10b9c2">
  <img src="https://a248.e.akamai.net/assets.github.com/images/modules/ajax/big_spinner_336699.gif?1315937721" height="32" width="32">
</div>

    </div>

    </div>

    <!-- footer -->
    <div id="footer" >
      
  <div class="upper_footer">
     <div class="site" class="clearfix">

       <!--[if IE]><h4 id="blacktocat_ie">GitHub Links</h4><![endif]-->
       <![if !IE]><h4 id="blacktocat">GitHub Links</h4><![endif]>

       <ul class="footer_nav">
         <h4>GitHub</h4>
         <li><a href="https://github.com/about">About</a></li>
         <li><a href="https://github.com/blog">Blog</a></li>
         <li><a href="https://github.com/features">Features</a></li>
         <li><a href="https://github.com/contact">Contact &amp; Support</a></li>
         <li><a href="https://github.com/training">Training</a></li>
         <li><a href="http://status.github.com/">Site Status</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Tools</h4>
         <li><a href="http://mac.github.com/">GitHub for Mac</a></li>
         <li><a href="http://mobile.github.com/">Issues for iPhone</a></li>
         <li><a href="https://gist.github.com">Gist: Code Snippets</a></li>
         <li><a href="http://enterprise.github.com/">GitHub Enterprise</a></li>
         <li><a href="http://jobs.github.com/">Job Board</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Extras</h4>
         <li><a href="http://shop.github.com/">GitHub Shop</a></li>
         <li><a href="http://octodex.github.com/">The Octodex</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Documentation</h4>
         <li><a href="http://help.github.com/">GitHub Help</a></li>
         <li><a href="http://developer.github.com/">Developer API</a></li>
         <li><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></li>
         <li><a href="http://pages.github.com/">GitHub Pages</a></li>
       </ul>

     </div><!-- /.site -->
  </div><!-- /.upper_footer -->

<div class="lower_footer">
  <div class="site" class="clearfix">
    <!--[if IE]><div id="legal_ie"><![endif]-->
    <![if !IE]><div id="legal"><![endif]>
      <ul>
          <li><a href="https://github.com/site/terms">Terms of Service</a></li>
          <li><a href="https://github.com/site/privacy">Privacy</a></li>
          <li><a href="https://github.com/security">Security</a></li>
      </ul>

      <p>&copy; 2011 <span id="_rrt" title="0.06180s from fe12.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
    </div><!-- /#legal or /#legal_ie-->

      <div class="sponsor">
        <a href="http://www.rackspace.com" class="logo">
          <img alt="Dedicated Server" height="36" src="https://a248.e.akamai.net/assets.github.com/images/modules/footer/rackspace_logo.png?v2" width="38" />
        </a>
        Powered by the <a href="http://www.rackspace.com ">Dedicated
        Servers</a> and<br/> <a href="http://www.rackspacecloud.com">Cloud
        Computing</a> of Rackspace Hosting<span>&reg;</span>
      </div>
  </div><!-- /.site -->
</div><!-- /.lower_footer -->

    </div><!-- /#footer -->

    

<div id="keyboard_shortcuts_pane" class="instapaper_ignore readability-extra" style="display:none">
  <h2>Keyboard Shortcuts <small><a href="#" class="js-see-all-keyboard-shortcuts">(see all)</a></small></h2>

  <div class="columns threecols">
    <div class="column first">
      <h3>Site wide shortcuts</h3>
      <dl class="keyboard-mappings">
        <dt>s</dt>
        <dd>Focus site search</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>?</dt>
        <dd>Bring up this help dialog</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column middle" style='display:none'>
      <h3>Commit list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>c <em>or</em> o <em>or</em> enter</dt>
        <dd>Open commit</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>y</dt>
        <dd>Expand URL to its canonical form</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column last" style='display:none'>
      <h3>Pull request list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>o <em>or</em> enter</dt>
        <dd>Open issue</dd>
      </dl>
    </div><!-- /.columns.last -->

  </div><!-- /.columns.equacols -->

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Issues</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>x</dt>
          <dd>Toggle selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column middle">
        <dl class="keyboard-mappings">
          <dt>I</dt>
          <dd>Mark selection as read</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>U</dt>
          <dd>Mark selection as unread</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>e</dt>
          <dd>Close selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Remove selection from view</dd>
        </dl>
      </div><!-- /.column.middle -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>c</dt>
          <dd>Create issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Create label</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>i</dt>
          <dd>Back to inbox</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>u</dt>
          <dd>Back to issues</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>/</dt>
          <dd>Focus issues search</dd>
        </dl>
      </div>
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Issues Dashboard</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Network Graph</h3>
    <div class="columns equacols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt><span class="badmono">←</span> <em>or</em> h</dt>
          <dd>Scroll left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">→</span> <em>or</em> l</dt>
          <dd>Scroll right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↑</span> <em>or</em> k</dt>
          <dd>Scroll up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↓</span> <em>or</em> j</dt>
          <dd>Scroll down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Toggle visibility of head labels</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">←</span> <em>or</em> shift h</dt>
          <dd>Scroll all the way left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">→</span> <em>or</em> shift l</dt>
          <dd>Scroll all the way right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↑</span> <em>or</em> shift k</dt>
          <dd>Scroll all the way up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↓</span> <em>or</em> shift j</dt>
          <dd>Scroll all the way down</dd>
        </dl>
      </div><!-- /.column.last -->
    </div>
  </div>

  <div >
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first" >
        <h3>Source Code Browsing</h3>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Activates the file finder</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Jump to line</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>w</dt>
          <dd>Switch branch/tag</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Expand URL to its canonical form</dd>
        </dl>
      </div>
    </div>
  </div>
</div>

    <div id="markdown-help" class="instapaper_ignore readability-extra">
  <h2>Markdown Cheat Sheet</h2>

  <div class="cheatsheet-content">

  <div class="mod">
    <div class="col">
      <h3>Format Text</h3>
      <p>Headers</p>
      <pre>
# This is an &lt;h1&gt; tag
## This is an &lt;h2&gt; tag
###### This is an &lt;h6&gt; tag</pre>
     <p>Text styles</p>
     <pre>
*This text will be italic*
_This will also be italic_
**This text will be bold**
__This will also be bold__

*You **can** combine them*
</pre>
    </div>
    <div class="col">
      <h3>Lists</h3>
      <p>Unordered</p>
      <pre>
* Item 1
* Item 2
  * Item 2a
  * Item 2b</pre>
     <p>Ordered</p>
     <pre>
1. Item 1
2. Item 2
3. Item 3
   * Item 3a
   * Item 3b</pre>
    </div>
    <div class="col">
      <h3>Miscellaneous</h3>
      <p>Images</p>
      <pre>
![GitHub Logo](/images/logo.png)
Format: ![Alt Text](url)
</pre>
     <p>Links</p>
     <pre>
http://github.com - automatic!
[GitHub](http://github.com)</pre>
<p>Blockquotes</p>
     <pre>
As Kanye West said:
> We're living the future so
> the present is our past.
</pre>
    </div>
  </div>
  <div class="rule"></div>

  <h3>Code Examples in Markdown</h3>
  <div class="col">
      <p>Syntax highlighting with <a href="http://github.github.com/github-flavored-markdown/" title="GitHub Flavored Markdown" target="_blank">GFM</a></p>
      <pre>
```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```</pre>
    </div>
    <div class="col">
      <p>Or, indent your code 4 spaces</p>
      <pre>
Here is a Python code example
without syntax highlighting:

    def foo:
      if not bar:
        return true</pre>
    </div>
    <div class="col">
      <p>Inline code for comments</p>
      <pre>
I think you should use an
`&lt;addr&gt;` element here instead.</pre>
    </div>
  </div>

  </div>
</div>

    <div class="context-overlay"></div>

    <div class="ajax-error-message">
      <p><span class="icon"></span> Something went wrong with that request. Please try again. <a href="javascript:;" class="ajax-error-dismiss">Dismiss</a></p>
    </div>

    
    
    
  </body>
</html>

