<!DOCTYPE html>
<html class="" lang="en">
<head prefix="og: http://ogp.me/ns#">
<meta charset="utf-8">
<meta content="IE=edge" http-equiv="X-UA-Compatible">
<meta content="object" property="og:type">
<meta content="GitLab" property="og:site_name">
<meta content="src/client.c · 8c40b964a0ab560f10c089be1f1eb4fa92551a91 · Fall19Group11 / Lab2" property="og:title">
<meta content="Welcome to LoboGit!" property="og:description">
<meta content="https://lobogit.unm.edu/assets/gitlab_logo-7ae504fe4f68fdebb3c2034e36621930cd36ea87924c11ff65dbcb8ed50dca58.png" property="og:image">
<meta content="64" property="og:image:width">
<meta content="64" property="og:image:height">
<meta content="https://lobogit.unm.edu/fall19group11/lab2/blob/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c" property="og:url">
<meta content="summary" property="twitter:card">
<meta content="src/client.c · 8c40b964a0ab560f10c089be1f1eb4fa92551a91 · Fall19Group11 / Lab2" property="twitter:title">
<meta content="Welcome to LoboGit!" property="twitter:description">
<meta content="https://lobogit.unm.edu/assets/gitlab_logo-7ae504fe4f68fdebb3c2034e36621930cd36ea87924c11ff65dbcb8ed50dca58.png" property="twitter:image">

<title>src/client.c · 8c40b964a0ab560f10c089be1f1eb4fa92551a91 · Fall19Group11 / Lab2 · GitLab</title>
<meta content="Welcome to LoboGit!" name="description">
<link rel="shortcut icon" type="image/png" href="/assets/favicon-7901bd695fb93edb07975966062049829afb56cf11511236e61bcf425070e36e.png" id="favicon" data-original-href="/assets/favicon-7901bd695fb93edb07975966062049829afb56cf11511236e61bcf425070e36e.png" />
<link rel="stylesheet" media="all" href="/assets/application-def1880ada798c68ee010ba2193f53a2c65a8981871a634ae7e18ccdcd503fa3.css" />
<link rel="stylesheet" media="print" href="/assets/print-74c3df10dad473d66660c828e3aa54ca3bfeac6d8bb708643331403fe7211e60.css" />


<link rel="stylesheet" media="all" href="/assets/highlight/themes/white-3144068cf4f603d290f553b653926358ddcd02493b9728f62417682657fc58c0.css" />
<script>
//<![CDATA[
window.gon={};gon.api_version="v4";gon.default_avatar_url="https://lobogit.unm.edu/assets/no_avatar-849f9c04a3a0d0cea2424ae97b27447dc64a7dbfae83c036c45b403392f0e8ba.png";gon.max_file_size=10;gon.asset_host=null;gon.webpack_public_path="/assets/webpack/";gon.relative_url_root="";gon.shortcuts_path="/help/shortcuts";gon.user_color_scheme="white";gon.gitlab_url="https://lobogit.unm.edu";gon.revision="2417d5becc7";gon.gitlab_logo="/assets/gitlab_logo-7ae504fe4f68fdebb3c2034e36621930cd36ea87924c11ff65dbcb8ed50dca58.png";gon.sprite_icons="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg";gon.sprite_file_icons="/assets/file_icons-7262fc6897e02f1ceaf8de43dc33afa5e4f9a2067f4f68ef77dcc87946575e9e.svg";gon.emoji_sprites_css_path="/assets/emoji_sprites-289eccffb1183c188b630297431be837765d9ff4aed6130cf738586fb307c170.css";gon.test_env=false;gon.suggested_label_colors={"#0033CC":"UA blue","#428BCA":"Moderate blue","#44AD8E":"Lime green","#A8D695":"Feijoa","#5CB85C":"Slightly desaturated green","#69D100":"Bright green","#004E00":"Very dark lime green","#34495E":"Very dark desaturated blue","#7F8C8D":"Dark grayish cyan","#A295D6":"Slightly desaturated blue","#5843AD":"Dark moderate blue","#8E44AD":"Dark moderate violet","#FFECDB":"Very pale orange","#AD4363":"Dark moderate pink","#D10069":"Strong pink","#CC0033":"Strong red","#FF0000":"Pure red","#D9534F":"Soft red","#D1D100":"Strong yellow","#F0AD4E":"Soft orange","#AD8D43":"Dark moderate orange"};gon.first_day_of_week=0;gon.ee=false;gon.current_user_id=543;gon.current_username="apedregon";gon.current_user_fullname="Arlin Pedregon Quezada";gon.current_user_avatar_url="https://secure.gravatar.com/avatar/7fc8c7dadc89ef5a265642e18d479448?s=80\u0026d=identicon";
//]]>
</script>


<script src="/assets/webpack/runtime.15f5b13a.bundle.js" defer="defer"></script>
<script src="/assets/webpack/main.f8ac0dda.chunk.js" defer="defer"></script>
<script src="/assets/webpack/commons~pages.admin.clusters~pages.admin.clusters.destroy~pages.admin.clusters.edit~pages.admin.clus~17e57b7f.1e0b3713.chunk.js" defer="defer"></script>
<script src="/assets/webpack/commons~pages.groups.milestones.edit~pages.groups.milestones.new~pages.projects.blame.show~pages.pro~d3e579ac.0dc404e7.chunk.js" defer="defer"></script>
<script src="/assets/webpack/pages.projects.blob.show.d9236e3f.chunk.js" defer="defer"></script>
<script>
//<![CDATA[
window.uploads_path = "/fall19group11/lab2/uploads";



//]]>
</script>
<meta name="csrf-param" content="authenticity_token" />
<meta name="csrf-token" content="udEmLXcJC7oG7/Ylcwlf5OQN3i/PusOIn59sn+dPfLReEGZrXzb4wbNT4NhRRJ8Uwt/CGq7RCX69VCXxAXS+bQ==" />

<meta content="origin-when-cross-origin" name="referrer">
<meta content="width=device-width, initial-scale=1, maximum-scale=1" name="viewport">
<meta content="#474D57" name="theme-color">
<link rel="apple-touch-icon" type="image/x-icon" href="/assets/touch-icon-iphone-5a9cee0e8a51212e70b90c87c12f382c428870c0ff67d1eb034d884b78d2dae7.png" />
<link rel="apple-touch-icon" type="image/x-icon" href="/assets/touch-icon-ipad-a6eec6aeb9da138e507593b464fdac213047e49d3093fc30e90d9a995df83ba3.png" sizes="76x76" />
<link rel="apple-touch-icon" type="image/x-icon" href="/assets/touch-icon-iphone-retina-72e2aadf86513a56e050e7f0f2355deaa19cc17ed97bbe5147847f2748e5a3e3.png" sizes="120x120" />
<link rel="apple-touch-icon" type="image/x-icon" href="/assets/touch-icon-ipad-retina-8ebe416f5313483d9c1bc772b5bbe03ecad52a54eba443e5215a22caed2a16a2.png" sizes="152x152" />
<link color="rgb(226, 67, 41)" href="/assets/logo-d36b5212042cebc89b96df4bf6ac24e43db316143e89926c0db839ff694d2de4.svg" rel="mask-icon">
<meta content="/assets/msapplication-tile-1196ec67452f618d39cdd85e2e3a542f76574c071051ae7effbfde01710eb17d.png" name="msapplication-TileImage">
<meta content="#30353E" name="msapplication-TileColor">




</head>

<body class="ui-indigo  gl-browser-chrome gl-platform-linux" data-find-file="/fall19group11/lab2/find_file/8c40b964a0ab560f10c089be1f1eb4fa92551a91" data-group="" data-page="projects:blob:show" data-project="lab2">

<script>
//<![CDATA[
gl = window.gl || {};
gl.client = {"isChrome":true,"isLinux":true};


//]]>
</script>


<header class="navbar navbar-gitlab navbar-expand-sm js-navbar" data-qa-selector="navbar">
<a class="sr-only gl-accessibility" href="#content-body" tabindex="1">Skip to content</a>
<div class="container-fluid">
<div class="header-content">
<div class="title-container">
<h1 class="title">
<a title="Dashboard" id="logo" href="/"><img class="brand-header-logo lazy" data-src="/uploads/-/system/appearance/header_logo/1/LoboGit.png" src="data:image/gif;base64,R0lGODlhAQABAAAAACH5BAEKAAEALAAAAAABAAEAAAICTAEAOw==" />
</a></h1>
<ul class="list-unstyled navbar-sub-nav">
<li id="nav-projects-dropdown" class="home dropdown header-projects qa-projects-dropdown" data-track-label="projects_dropdown" data-track-event="click_dropdown" data-track-value=""><button class="btn" data-toggle="dropdown" type="button">
Projects
<svg class="caret-down"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-down"></use></svg>
</button>
<div class="dropdown-menu frequent-items-dropdown-menu">
<div class="frequent-items-dropdown-container">
<div class="frequent-items-dropdown-sidebar qa-projects-dropdown-sidebar">
<ul>
<li class=""><a class="qa-your-projects-link" href="/dashboard/projects">Your projects
</a></li><li class=""><a href="/dashboard/projects/starred">Starred projects
</a></li><li class=""><a href="/explore">Explore projects
</a></li></ul>
</div>
<div class="frequent-items-dropdown-content">
<div data-project-id="1809" data-project-name="Lab2" data-project-namespace="Fall19Group11 / Lab2" data-project-web-url="/fall19group11/lab2" data-user-name="apedregon" id="js-projects-dropdown"></div>
</div>
</div>

</div>
</li><li id="nav-groups-dropdown" class="home dropdown header-groups qa-groups-dropdown" data-track-label="groups_dropdown" data-track-event="click_dropdown" data-track-value=""><button class="btn" data-toggle="dropdown" type="button">
Groups
<svg class="caret-down"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-down"></use></svg>
</button>
<div class="dropdown-menu frequent-items-dropdown-menu">
<div class="frequent-items-dropdown-container">
<div class="frequent-items-dropdown-sidebar qa-groups-dropdown-sidebar">
<ul>
<li class=""><a class="qa-your-groups-link" href="/dashboard/groups">Your groups
</a></li><li class=""><a href="/explore/groups">Explore groups
</a></li></ul>
</div>
<div class="frequent-items-dropdown-content">
<div data-user-name="apedregon" id="js-groups-dropdown"></div>
</div>
</div>

</div>
</li><li class="d-none d-xl-block"><a class="dashboard-shortcuts-activity" href="/dashboard/activity">Activity
</a></li><li class="d-none d-xl-block"><a class="dashboard-shortcuts-milestones" href="/dashboard/milestones">Milestones
</a></li><li class="d-none d-xl-block"><a class="dashboard-shortcuts-snippets qa-snippets-link" href="/dashboard/snippets">Snippets
</a></li>
<li class="d-xl-none dropdown header-more">
<a data-toggle="dropdown" href="#">
More
<svg class="caret-down"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-down"></use></svg>
</a>
<div class="dropdown-menu">
<ul>
<li class=""><a href="/dashboard/activity">Activity
</a></li><li class=""><a class="dashboard-shortcuts-milestones" href="/dashboard/milestones">Milestones
</a></li><li class=""><a class="dashboard-shortcuts-snippets" href="/dashboard/snippets">Snippets
</a></li>
<li class="dropdown d-lg-none">

</li>
<li class="d-lg-none"><a href="/-/instance_statistics">Instance Statistics
</a></li></ul>
</div>
</li>
<li class="hidden">
<a class="dashboard-shortcuts-projects" href="/dashboard/projects">Projects
</a></li>
<li class="d-lg-block d-none dropdown">

</li>
<li class="d-none d-lg-block d-xl-block"><a title="Instance Statistics" aria-label="Instance Statistics" data-toggle="tooltip" data-placement="bottom" data-container="body" href="/-/instance_statistics"><svg class="s18"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#chart"></use></svg>
</a></li>
</ul>

</div>
<div class="navbar-collapse collapse">
<ul class="nav navbar-nav">
<li class="header-new dropdown" data-track-event="click_dropdown" data-track-label="new_dropdown" data-track-value="">
<a class="header-new-dropdown-toggle has-tooltip qa-new-menu-toggle" id="js-onboarding-new-project-link" title="New..." ref="tooltip" aria-label="New..." data-toggle="dropdown" data-placement="bottom" data-container="body" data-display="static" href="/projects/new"><svg class="s16"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#plus-square"></use></svg>
<svg class="caret-down"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-down"></use></svg>
</a><div class="dropdown-menu dropdown-menu-right">
<ul>
<li class="dropdown-bold-header">
This project
</li>
<li><a href="/fall19group11/lab2/issues/new">New issue</a></li>
<li><a href="/fall19group11/lab2/merge_requests/new">New merge request</a></li>
<li><a href="/fall19group11/lab2/snippets/new">New snippet</a></li>
<li class="divider"></li>
<li class="dropdown-bold-header">GitLab</li>
<li><a class="qa-global-new-project-link" href="/projects/new">New project</a></li>
<li><a href="/groups/new">New group</a></li>
<li><a class="qa-global-new-snippet-link" href="/snippets/new">New snippet</a></li>
</ul>
</div>
</li>

<li class="nav-item d-none d-sm-none d-md-block m-auto">
<div class="search search-form" data-track-event="activate_form_input" data-track-label="navbar_search" data-track-value="">
<form class="form-inline" action="/search" accept-charset="UTF-8" method="get"><input name="utf8" type="hidden" value="&#x2713;" /><div class="search-input-container">
<div class="search-input-wrap">
<div class="dropdown" data-url="/search/autocomplete">
<input type="search" name="search" id="search" placeholder="Search or jump to…" class="search-input dropdown-menu-toggle no-outline js-search-dashboard-options" spellcheck="false" tabindex="1" autocomplete="off" data-issues-path="/dashboard/issues" data-mr-path="/dashboard/merge_requests" data-qa-selector="search_term_field" aria-label="Search or jump to…" />
<button class="hidden js-dropdown-search-toggle" data-toggle="dropdown" type="button"></button>
<div class="dropdown-menu dropdown-select js-dashboard-search-options">
<div class="dropdown-content"><ul>
<li class="dropdown-menu-empty-item">
<a>
Loading...
</a>
</li>
</ul>
</div><div class="dropdown-loading"><i aria-hidden="true" data-hidden="true" class="fa fa-spinner fa-spin"></i></div>
</div>
<svg class="s16 search-icon"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#search"></use></svg>
<svg class="s16 clear-icon js-clear-input"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#close"></use></svg>
</div>
</div>
</div>
<input type="hidden" name="group_id" id="group_id" class="js-search-group-options" />
<input type="hidden" name="project_id" id="search_project_id" value="1809" class="js-search-project-options" data-project-path="lab2" data-name="Lab2" data-issues-path="/fall19group11/lab2/issues" data-mr-path="/fall19group11/lab2/merge_requests" data-issues-disabled="false" />
<input type="hidden" name="search_code" id="search_code" value="true" />
<input type="hidden" name="repository_ref" id="repository_ref" value="8c40b964a0ab560f10c089be1f1eb4fa92551a91" />
<input type="hidden" name="nav_source" id="nav_source" value="navbar" />
<div class="search-autocomplete-opts hide" data-autocomplete-path="/search/autocomplete" data-autocomplete-project-id="1809" data-autocomplete-project-ref="8c40b964a0ab560f10c089be1f1eb4fa92551a91"></div>
</form></div>

</li>
<li class="nav-item d-inline-block d-sm-none d-md-none">
<a title="Search" aria-label="Search" data-toggle="tooltip" data-placement="bottom" data-container="body" href="/search?project_id=1809"><svg class="s16"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#search"></use></svg>
</a></li>
<li class="user-counter"><a title="Issues" class="dashboard-shortcuts-issues" aria-label="Issues" data-toggle="tooltip" data-placement="bottom" data-container="body" href="/dashboard/issues?assignee_username=apedregon"><svg class="s16"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#issues"></use></svg>
<span class="badge badge-pill green-badge hidden issues-count">
0
</span>
</a></li><li class="user-counter"><a title="Merge requests" class="dashboard-shortcuts-merge_requests" aria-label="Merge requests" data-toggle="tooltip" data-placement="bottom" data-container="body" href="/dashboard/merge_requests?assignee_username=apedregon"><svg class="s16"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#git-merge"></use></svg>
<span class="badge badge-pill hidden merge-requests-count">
0
</span>
</a></li><li class="user-counter"><a title="To-Do List" aria-label="To-Do List" class="shortcuts-todos" data-toggle="tooltip" data-placement="bottom" data-container="body" href="/dashboard/todos"><svg class="s16"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#todo-done"></use></svg>
<span class="badge badge-pill hidden todos-count">
0
</span>
</a></li><li class="nav-item header-help dropdown">
<a class="header-help-dropdown-toggle" data-toggle="dropdown" href="/help"><svg class="s16"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#question"></use></svg>
<svg class="caret-down"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-down"></use></svg>
</a><div class="dropdown-menu dropdown-menu-right">
<ul>
<li>
<a href="/help">Help</a>
</li>
<li>
<a href="https://about.gitlab.com/getting-help/">Support</a>
</li>

<li class="divider"></li>
<li>
<a href="https://about.gitlab.com/submit-feedback">Submit feedback</a>
</li>
<li>
<a target="_blank" class="text-nowrap" href="https://about.gitlab.com/contributing">Contribute to GitLab
</a></li>


</ul>

</div>
</li>
<li class="dropdown header-user nav-item" data-qa-selector="user_menu" data-track-event="click_dropdown" data-track-label="profile_dropdown" data-track-value="">
<a class="header-user-dropdown-toggle" data-toggle="dropdown" href="/apedregon"><img width="23" height="23" class="header-user-avatar qa-user-avatar lazy" data-src="https://secure.gravatar.com/avatar/7fc8c7dadc89ef5a265642e18d479448?s=46&amp;d=identicon" src="data:image/gif;base64,R0lGODlhAQABAAAAACH5BAEKAAEALAAAAAABAAEAAAICTAEAOw==" />
<svg class="caret-down"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-down"></use></svg>
</a><div class="dropdown-menu dropdown-menu-right">
<ul>
<li class="current-user">
<div class="user-name bold">
Arlin Pedregon Quezada
</div>
@apedregon
</li>
<li class="divider"></li>
<li>
<div class="js-set-status-modal-trigger" data-has-status="false"></div>
</li>
<li>
<a class="profile-link" data-user="apedregon" href="/apedregon">Profile</a>
</li>
<li>
<a data-qa-selector="settings_link" href="/profile">Settings</a>
</li>
<li class="divider"></li>
<li>
<a class="sign-out-link" data-qa-selector="sign_out_link" href="/users/sign_out">Sign out</a>
</li>
</ul>

</div>
</li>
</ul>
</div>
<button class="navbar-toggler d-block d-sm-none" type="button">
<span class="sr-only">Toggle navigation</span>
<svg class="s12 more-icon js-navbar-toggle-right"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#ellipsis_h"></use></svg>
<svg class="s12 close-icon js-navbar-toggle-left"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#close"></use></svg>
</button>
</div>
</div>
</header>
<div class="js-set-status-modal-wrapper" data-current-emoji="" data-current-message=""></div>

<div class="layout-page page-with-contextual-sidebar">
<div class="nav-sidebar">
<div class="nav-sidebar-inner-scroll">
<div class="context-header">
<a title="Lab2" href="/fall19group11/lab2"><div class="avatar-container rect-avatar s40 project-avatar">
<div class="avatar s40 avatar-tile identicon bg4">L</div>
</div>
<div class="sidebar-context-title">
Lab2
</div>
</a></div>
<ul class="sidebar-top-level-items">
<li class="home"><a class="shortcuts-project rspec-project-link" data-qa-selector="project_link" href="/fall19group11/lab2"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#home"></use></svg>
</div>
<span class="nav-item-name">
Project
</span>
</a><ul class="sidebar-sub-level-items">
<li class="fly-out-top-item"><a href="/fall19group11/lab2"><strong class="fly-out-top-item-name">
Project
</strong>
</a></li><li class="divider fly-out-top-item"></li>
<li class=""><a title="Project details" class="shortcuts-project" href="/fall19group11/lab2"><span>Details</span>
</a></li><li class=""><a title="Activity" class="shortcuts-project-activity" data-qa-selector="activity_link" href="/fall19group11/lab2/activity"><span>Activity</span>
</a></li><li class=""><a title="Releases" class="shortcuts-project-releases" href="/fall19group11/lab2/-/releases"><span>Releases</span>
</a></li><li class=""><a title="Cycle Analytics" class="shortcuts-project-cycle-analytics" href="/fall19group11/lab2/cycle_analytics"><span>Cycle Analytics</span>
</a></li>
</ul>
</li><li class="active"><a class="shortcuts-tree qa-project-menu-repo" href="/fall19group11/lab2/tree/8c40b964a0ab560f10c089be1f1eb4fa92551a91"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#doc-text"></use></svg>
</div>
<span class="nav-item-name" id="js-onboarding-repo-link">
Repository
</span>
</a><ul class="sidebar-sub-level-items">
<li class="fly-out-top-item active"><a href="/fall19group11/lab2/tree/8c40b964a0ab560f10c089be1f1eb4fa92551a91"><strong class="fly-out-top-item-name">
Repository
</strong>
</a></li><li class="divider fly-out-top-item"></li>
<li class="active"><a href="/fall19group11/lab2/tree/8c40b964a0ab560f10c089be1f1eb4fa92551a91">Files
</a></li><li class=""><a id="js-onboarding-commits-link" href="/fall19group11/lab2/commits/8c40b964a0ab560f10c089be1f1eb4fa92551a91">Commits
</a></li><li class=""><a class="qa-branches-link" id="js-onboarding-branches-link" href="/fall19group11/lab2/-/branches">Branches
</a></li><li class=""><a href="/fall19group11/lab2/-/tags">Tags
</a></li><li class=""><a href="/fall19group11/lab2/-/graphs/8c40b964a0ab560f10c089be1f1eb4fa92551a91">Contributors
</a></li><li class=""><a href="/fall19group11/lab2/-/network/8c40b964a0ab560f10c089be1f1eb4fa92551a91">Graph
</a></li><li class=""><a href="/fall19group11/lab2/compare?from=master&amp;to=8c40b964a0ab560f10c089be1f1eb4fa92551a91">Compare
</a></li><li class=""><a href="/fall19group11/lab2/-/graphs/8c40b964a0ab560f10c089be1f1eb4fa92551a91/charts">Charts
</a></li>
</ul>
</li><li class=""><a class="shortcuts-issues qa-issues-item" href="/fall19group11/lab2/issues"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#issues"></use></svg>
</div>
<span class="nav-item-name" id="js-onboarding-issues-link">
Issues
</span>
<span class="badge badge-pill count issue_counter">
0
</span>
</a><ul class="sidebar-sub-level-items">
<li class="fly-out-top-item"><a href="/fall19group11/lab2/issues"><strong class="fly-out-top-item-name">
Issues
</strong>
<span class="badge badge-pill count issue_counter fly-out-badge">
0
</span>
</a></li><li class="divider fly-out-top-item"></li>
<li class=""><a title="Issues" href="/fall19group11/lab2/issues"><span>
List
</span>
</a></li><li class=""><a title="Boards" data-qa-selector="issue_boards_link" href="/fall19group11/lab2/-/boards"><span>
Boards
</span>
</a></li><li class=""><a title="Labels" class="qa-labels-link" href="/fall19group11/lab2/-/labels"><span>
Labels
</span>
</a></li>
<li class=""><a title="Milestones" class="qa-milestones-link" href="/fall19group11/lab2/-/milestones"><span>
Milestones
</span>
</a></li></ul>
</li><li class=""><a class="shortcuts-merge_requests" data-qa-selector="merge_requests_link" href="/fall19group11/lab2/merge_requests"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#git-merge"></use></svg>
</div>
<span class="nav-item-name" id="js-onboarding-mr-link">
Merge Requests
</span>
<span class="badge badge-pill count merge_counter js-merge-counter">
0
</span>
</a><ul class="sidebar-sub-level-items is-fly-out-only">
<li class="fly-out-top-item"><a href="/fall19group11/lab2/merge_requests"><strong class="fly-out-top-item-name">
Merge Requests
</strong>
<span class="badge badge-pill count merge_counter js-merge-counter fly-out-badge">
0
</span>
</a></li></ul>
</li><li class=""><a class="shortcuts-pipelines qa-link-pipelines rspec-link-pipelines" href="/fall19group11/lab2/pipelines"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#rocket"></use></svg>
</div>
<span class="nav-item-name" id="js-onboarding-pipelines-link">
CI / CD
</span>
</a><ul class="sidebar-sub-level-items">
<li class="fly-out-top-item"><a href="/fall19group11/lab2/pipelines"><strong class="fly-out-top-item-name">
CI / CD
</strong>
</a></li><li class="divider fly-out-top-item"></li>
<li class=""><a title="Pipelines" class="shortcuts-pipelines" href="/fall19group11/lab2/pipelines"><span>
Pipelines
</span>
</a></li><li class=""><a title="Jobs" class="shortcuts-builds" href="/fall19group11/lab2/-/jobs"><span>
Jobs
</span>
</a></li><li class=""><a title="Schedules" class="shortcuts-builds" href="/fall19group11/lab2/pipeline_schedules"><span>
Schedules
</span>
</a></li><li class=""><a title="Charts" class="shortcuts-pipelines-charts" href="/fall19group11/lab2/pipelines/charts"><span>
Charts
</span>
</a></li></ul>
</li>
<li class=""><a class="shortcuts-operations qa-link-operations" href="/fall19group11/lab2/environments/metrics"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#cloud-gear"></use></svg>
</div>
<span class="nav-item-name">
Operations
</span>
</a><ul class="sidebar-sub-level-items">
<li class="fly-out-top-item"><a href="/fall19group11/lab2/environments/metrics"><strong class="fly-out-top-item-name">
Operations
</strong>
</a></li><li class="divider fly-out-top-item"></li>
<li class=""><a title="Metrics" class="shortcuts-metrics" href="/fall19group11/lab2/environments/metrics"><span>
Metrics
</span>
</a></li>
<li class=""><a title="Environments" class="shortcuts-environments qa-operations-environments-link" href="/fall19group11/lab2/environments"><span>
Environments
</span>
</a></li><li class=""><a title="Error Tracking" class="shortcuts-tracking qa-operations-tracking-link" href="/fall19group11/lab2/error_tracking"><span>
Error Tracking
</span>
</a></li><li class=""><a title="Serverless" href="/fall19group11/lab2/serverless/functions"><span>
Serverless
</span>
</a></li><li class=""><a title="Kubernetes" class="shortcuts-kubernetes" href="/fall19group11/lab2/clusters"><span>
Kubernetes
</span>
<div class="feature-highlight js-feature-highlight" data-container="body" data-dismiss-endpoint="/-/user_callouts" data-highlight="gke_cluster_integration" data-placement="right" data-toggle="popover" data-trigger="manual" disabled></div>
</a><div class="feature-highlight-popover-content">
<img class="feature-highlight-illustration lazy" data-src="/assets/illustrations/cluster_popover-889b8203a86c86d1fd3f0b181e588071d00cd9c77590fd87dba4d19035e1c0df.svg" src="data:image/gif;base64,R0lGODlhAQABAAAAACH5BAEKAAEALAAAAAABAAEAAAICTAEAOw==" />
<div class="feature-highlight-popover-sub-content">
<p>Allows you to add and manage Kubernetes clusters.</p>
<p>
Protip:
<a href="/help/topics/autodevops/index.md">Auto DevOps</a>
<span>uses Kubernetes clusters to deploy your code!</span>
</p>
<hr>
<button class="btn btn-success btn-sm dismiss-feature-highlight" type="button">
<span>Got it!</span>
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#thumb-up"></use></svg>
</button>
</div>
</div>
</li>
</ul>
</li>
<li class=""><a class="shortcuts-wiki" data-qa-selector="wiki_link" href="/fall19group11/lab2/wikis/home"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#book"></use></svg>
</div>
<span class="nav-item-name">
Wiki
</span>
</a><ul class="sidebar-sub-level-items is-fly-out-only">
<li class="fly-out-top-item"><a href="/fall19group11/lab2/wikis/home"><strong class="fly-out-top-item-name">
Wiki
</strong>
</a></li></ul>
</li><li class=""><a class="shortcuts-snippets" href="/fall19group11/lab2/snippets"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#snippet"></use></svg>
</div>
<span class="nav-item-name">
Snippets
</span>
</a><ul class="sidebar-sub-level-items is-fly-out-only">
<li class="fly-out-top-item"><a href="/fall19group11/lab2/snippets"><strong class="fly-out-top-item-name">
Snippets
</strong>
</a></li></ul>
</li><li class=""><a class="shortcuts-tree" href="/fall19group11/lab2/edit"><div class="nav-icon-container">
<svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#settings"></use></svg>
</div>
<span class="nav-item-name qa-settings-item" id="js-onboarding-settings-link">
Settings
</span>
</a><ul class="sidebar-sub-level-items">
<li class="fly-out-top-item"><a href="/fall19group11/lab2/edit"><strong class="fly-out-top-item-name">
Settings
</strong>
</a></li><li class="divider fly-out-top-item"></li>
<li class=""><a title="General" class="qa-general-settings-link" href="/fall19group11/lab2/edit"><span>
General
</span>
</a></li><li class=""><a title="Members" class="qa-link-members-settings" id="js-onboarding-settings-members-link" href="/fall19group11/lab2/-/project_members"><span>
Members
</span>
</a></li><li class=""><a title="Integrations" href="/fall19group11/lab2/-/settings/integrations"><span>
Integrations
</span>
</a></li><li class=""><a title="Repository" href="/fall19group11/lab2/-/settings/repository"><span>
Repository
</span>
</a></li><li class=""><a title="CI / CD" href="/fall19group11/lab2/-/settings/ci_cd"><span>
CI / CD
</span>
</a></li><li class=""><a title="Operations" href="/fall19group11/lab2/-/settings/operations">Operations
</a></li>
</ul>
</li><a class="toggle-sidebar-button js-toggle-sidebar qa-toggle-sidebar rspec-toggle-sidebar" role="button" title="Toggle sidebar" type="button">
<svg class="icon-angle-double-left"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-double-left"></use></svg>
<svg class="icon-angle-double-right"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-double-right"></use></svg>
<span class="collapse-text">Collapse sidebar</span>
</a>
<button name="button" type="button" class="close-nav-button"><svg class="s16"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#close"></use></svg>
<span class="collapse-text">Close sidebar</span>
</button>
<li class="hidden">
<a title="Activity" class="shortcuts-project-activity" href="/fall19group11/lab2/activity"><span>
Activity
</span>
</a></li>
<li class="hidden">
<a title="Network" class="shortcuts-network" href="/fall19group11/lab2/-/network/8c40b964a0ab560f10c089be1f1eb4fa92551a91">Graph
</a></li>
<li class="hidden">
<a title="Charts" class="shortcuts-repository-charts" href="/fall19group11/lab2/-/graphs/8c40b964a0ab560f10c089be1f1eb4fa92551a91/charts">Charts
</a></li>
<li class="hidden">
<a class="shortcuts-new-issue" href="/fall19group11/lab2/issues/new">Create a new issue
</a></li>
<li class="hidden">
<a title="Jobs" class="shortcuts-builds" href="/fall19group11/lab2/-/jobs">Jobs
</a></li>
<li class="hidden">
<a title="Commits" class="shortcuts-commits" href="/fall19group11/lab2/commits/8c40b964a0ab560f10c089be1f1eb4fa92551a91">Commits
</a></li>
<li class="hidden">
<a title="Issue Boards" class="shortcuts-issue-boards" href="/fall19group11/lab2/-/boards">Issue Boards</a>
</li>
</ul>
</div>
</div>

<div class="content-wrapper">

<div class="mobile-overlay"></div>
<div class="alert-wrapper">






<nav class="breadcrumbs container-fluid container-limited" role="navigation">
<div class="breadcrumbs-container">
<button name="button" type="button" class="toggle-mobile-nav"><span class="sr-only">Open sidebar</span>
<i aria-hidden="true" data-hidden="true" class="fa fa-bars"></i>
</button><div class="breadcrumbs-links js-title-container">
<ul class="list-unstyled breadcrumbs-list js-breadcrumbs-list">
<li><a class="group-path breadcrumb-item-text js-breadcrumb-item-text " href="/fall19group11">Fall19Group11</a><svg class="s8 breadcrumbs-list-angle"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-right"></use></svg></li> <li><a href="/fall19group11/lab2"><span class="breadcrumb-item-text js-breadcrumb-item-text">Lab2</span></a><svg class="s8 breadcrumbs-list-angle"><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#angle-right"></use></svg></li>

<li>
<h2 class="breadcrumbs-sub-title"><a href="/fall19group11/lab2/blob/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c">Repository</a></h2>
</li>
</ul>
</div>

</div>
</nav>

<div class="d-flex"></div>
</div>
<div class="container-fluid container-limited ">
<div class="content" id="content-body">
<div class="flash-container flash-container-page sticky">
</div>

<div class="js-signature-container" data-signatures-path="/fall19group11/lab2/commits/8c40b964a0ab560f10c089be1f1eb4fa92551a91/signatures"></div>

<div class="tree-holder" id="tree-holder">
<div class="nav-block">
<div class="tree-ref-container">
<div class="tree-ref-holder">
<form class="project-refs-form" action="/fall19group11/lab2/refs/switch" accept-charset="UTF-8" method="get"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="destination" id="destination" value="blob" />
<input type="hidden" name="path" id="path" value="src/client.c" />
<div class="dropdown">
<button class="dropdown-menu-toggle js-project-refs-dropdown qa-branches-select" type="button" data-toggle="dropdown" data-selected="8c40b964a0ab560f10c089be1f1eb4fa92551a91" data-ref="8c40b964a0ab560f10c089be1f1eb4fa92551a91" data-refs-url="/fall19group11/lab2/refs?sort=updated_desc" data-field-name="ref" data-submit-form-on-click="true" data-visit="true"><span class="dropdown-toggle-text ">8c40b964a0ab560f10c089be1f1eb4fa92551a91</span><i aria-hidden="true" data-hidden="true" class="fa fa-chevron-down"></i></button>
<div class="dropdown-menu dropdown-menu-paging dropdown-menu-selectable git-revision-dropdown qa-branches-dropdown">
<div class="dropdown-page-one">
<div class="dropdown-title"><span>Switch branch/tag</span><button class="dropdown-title-button dropdown-menu-close" aria-label="Close" type="button"><i aria-hidden="true" data-hidden="true" class="fa fa-times dropdown-menu-close-icon"></i></button></div>
<div class="dropdown-input"><input type="search" id="" class="dropdown-input-field qa-dropdown-input-field" placeholder="Search branches and tags" autocomplete="off" /><i aria-hidden="true" data-hidden="true" class="fa fa-search dropdown-input-search"></i><i aria-hidden="true" data-hidden="true" role="button" class="fa fa-times dropdown-input-clear js-dropdown-input-clear"></i></div>
<div class="dropdown-content"></div>
<div class="dropdown-loading"><i aria-hidden="true" data-hidden="true" class="fa fa-spinner fa-spin"></i></div>
</div>
</div>
</div>
</form>
</div>
<ul class="breadcrumb repo-breadcrumb">
<li class="breadcrumb-item">
<a href="/fall19group11/lab2/tree/8c40b964a0ab560f10c089be1f1eb4fa92551a91">lab2
</a></li>
<li class="breadcrumb-item">
<a href="/fall19group11/lab2/tree/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src">src</a>
</li>
<li class="breadcrumb-item">
<a href="/fall19group11/lab2/blob/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c"><strong>client.c</strong>
</a></li>
</ul>
</div>
<div class="tree-controls">
<a class="btn shortcuts-find-file" rel="nofollow" href="/fall19group11/lab2/find_file/8c40b964a0ab560f10c089be1f1eb4fa92551a91"><i aria-hidden="true" data-hidden="true" class="fa fa-search"></i>
<span>Find file</span>
</a>
<div class="btn-group" role="group"><a class="btn js-blob-blame-link" href="/fall19group11/lab2/blame/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c">Blame</a><a class="btn" href="/fall19group11/lab2/commits/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c">History</a><a class="btn js-data-file-blob-permalink-url" href="/fall19group11/lab2/blob/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c">Permalink</a></div>
</div>
</div>

<div class="info-well d-none d-sm-block">
<div class="well-segment">
<ul class="blob-commit-info">
<li class="commit flex-row js-toggle-container" id="commit-8c40b964">
<div class="avatar-cell d-none d-sm-block">
<a href="/lpascoe"><img alt="Lauren Pascoe&#39;s avatar" src="https://secure.gravatar.com/avatar/01cb4e41eb22b5c5e940e6cca5f11bab?s=80&amp;d=identicon" class="avatar s40 d-none d-sm-inline-block" title="Lauren Pascoe" /></a>
</div>
<div class="commit-detail flex-list">
<div class="commit-content qa-commit-content">
<a class="commit-row-message item-title js-onboarding-commit-item" href="/fall19group11/lab2/commit/8c40b964a0ab560f10c089be1f1eb4fa92551a91">reformatting.</a>
<span class="commit-row-message d-inline d-sm-none">
&middot;
8c40b964
</span>
<div class="committer">
<a class="commit-author-link js-user-link" data-user-id="763" href="/lpascoe">Lauren Pascoe</a> authored <time class="js-timeago" title="Oct 19, 2019 12:34am" datetime="2019-10-19T00:34:33Z" data-toggle="tooltip" data-placement="bottom" data-container="body">Oct 19, 2019</time>
</div>

</div>
<div class="commit-actions flex-row">

<div class="js-commit-pipeline-status" data-endpoint="/fall19group11/lab2/commit/8c40b964a0ab560f10c089be1f1eb4fa92551a91/pipelines?ref=8c40b964a0ab560f10c089be1f1eb4fa92551a91"></div>
<div class="commit-sha-group d-none d-sm-flex">
<div class="label label-monospace monospace">
8c40b964
</div>
<button class="btn btn btn-default" data-toggle="tooltip" data-placement="bottom" data-container="body" data-title="Copy commit SHA to clipboard" data-class="btn btn-default" data-clipboard-text="8c40b964a0ab560f10c089be1f1eb4fa92551a91" type="button" title="Copy commit SHA to clipboard" aria-label="Copy commit SHA to clipboard"><svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#duplicate"></use></svg></button>

</div>
</div>
</div>
</li>

</ul>
</div>


</div>
<div class="blob-content-holder" id="blob-content-holder">
<article class="file-holder">
<div class="js-file-title file-title-flex-parent">
<div class="file-header-content">
<i aria-hidden="true" data-hidden="true" class="fa fa-file-text-o fa-fw"></i>
<strong class="file-title-name qa-file-title-name">
client.c
</strong>
<button class="btn btn-clipboard btn-transparent" data-toggle="tooltip" data-placement="bottom" data-container="body" data-class="btn-clipboard btn-transparent" data-title="Copy file path to clipboard" data-clipboard-text="{&quot;text&quot;:&quot;src/client.c&quot;,&quot;gfm&quot;:&quot;`src/client.c`&quot;}" type="button" title="Copy file path to clipboard" aria-label="Copy file path to clipboard"><svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#duplicate"></use></svg></button>
<small class="mr-1">
4.29 KB
</small>
</div>

<div class="file-actions">

<div class="btn-group" role="group"><button class="btn btn btn-sm js-copy-blob-source-btn" data-toggle="tooltip" data-placement="bottom" data-container="body" data-class="btn btn-sm js-copy-blob-source-btn" data-title="Copy source to clipboard" data-clipboard-target=".blob-content[data-blob-id=&#39;c8b4a5ee6bb5fc2fb0efa0c8a9c1254666ed02ea&#39;]" type="button" title="Copy source to clipboard" aria-label="Copy source to clipboard"><svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#duplicate"></use></svg></button><a class="btn btn-sm has-tooltip" target="_blank" rel="noopener noreferrer" title="Open raw" data-container="body" href="/fall19group11/lab2/raw/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c"><i aria-hidden="true" data-hidden="true" class="fa fa-file-code-o"></i></a><a download="src/client.c" class="btn btn-sm has-tooltip" target="_blank" rel="noopener noreferrer" title="Download" data-container="body" href="/fall19group11/lab2/raw/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c?inline=false"><svg><use xlink:href="/assets/icons-4009ebf96719f129f954d643e65f87152b5e6c4a4917130c4a696beb54af9949.svg#download"></use></svg></a></div>
<div class="btn-group" role="group"><button name="button" type="submit" class="btn js-edit-blob  disabled has-tooltip" title="You can only edit files when you are on a branch" data-container="body">Edit</button><button name="button" type="submit" class="btn btn-default disabled has-tooltip" title="You can only edit files when you are on a branch" data-container="body">Web IDE</button><button name="button" type="submit" class="btn btn-default disabled has-tooltip" title="You can only replace files when you are on a branch" data-container="body">Replace</button><button name="button" type="submit" class="btn btn-remove disabled has-tooltip" title="You can only delete files when you are on a branch" data-container="body">Delete</button></div>
</div>
</div>
<div class="js-file-fork-suggestion-section file-fork-suggestion hidden">
<span class="file-fork-suggestion-note">
You're not allowed to
<span class="js-file-fork-suggestion-section-action">
edit
</span>
files in this project directly. Please fork this project,
make your changes there, and submit a merge request.
</span>
<a class="js-fork-suggestion-button btn btn-grouped btn-inverted btn-success" rel="nofollow" data-method="post" href="/fall19group11/lab2/blob/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c">Fork</a>
<button class="js-cancel-fork-suggestion-button btn btn-grouped" type="button">
Cancel
</button>
</div>



<div class="blob-viewer" data-type="simple" data-url="/fall19group11/lab2/blob/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c?format=json&amp;viewer=simple">
<div class="text-center prepend-top-default append-bottom-default">
<i aria-hidden="true" aria-label="Loading content…" class="fa fa-spinner fa-spin fa-2x qa-spinner"></i>
</div>

</div>


</article>
</div>

<div class="modal" id="modal-upload-blob">
<div class="modal-dialog modal-lg">
<div class="modal-content">
<div class="modal-header">
<h3 class="page-title">Replace client.c</h3>
<button aria-label="Close" class="close" data-dismiss="modal" type="button">
<span aria-hidden="true">&times;</span>
</button>
</div>
<div class="modal-body">
<form class="js-quick-submit js-upload-blob-form" data-method="put" action="/fall19group11/lab2/update/8c40b964a0ab560f10c089be1f1eb4fa92551a91/src/client.c" accept-charset="UTF-8" method="post"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="_method" value="put" /><input type="hidden" name="authenticity_token" value="F7SkJSrL1TY3sc7IlBwQc4bR+QiZmvKOxdwlwW5uG1zwdeRjAvQmTYIN2DW2UdCDoAPlPfjxOHjnF2yviFXZhQ==" /><div class="dropzone">
<div class="dropzone-previews blob-upload-dropzone-previews">
<p class="dz-message light">
Attach a file by drag &amp; drop or <a class="markdown-selector" href="#">click to upload</a>
</p>
</div>
</div>
<br>
<div class="dropzone-alerts alert alert-danger data" style="display:none"></div>
<div class="form-group row commit_message-group">
<label class="col-form-label col-sm-2" for="commit_message-5d84ae465fc00ac1d5ea02606b3cb3ac">Commit message
</label><div class="col-sm-10">
<div class="commit-message-container">
<div class="max-width-marker"></div>
<textarea name="commit_message" id="commit_message-5d84ae465fc00ac1d5ea02606b3cb3ac" class="form-control js-commit-message" placeholder="Replace client.c" required="required" rows="3">
Replace client.c</textarea>
</div>
</div>
</div>

<div class="form-group row branch">
<label class="col-form-label col-sm-2" for="branch_name">Target Branch</label>
<div class="col-sm-10">
<input type="text" name="branch_name" id="branch_name" required="required" class="form-control js-branch-name ref-name" />
<div class="js-create-merge-request-container">
<div class="form-check prepend-top-8">
<input type="checkbox" name="create_merge_request" id="create_merge_request-00242ff00f3dec678d597accdf5bb398" value="1" class="js-create-merge-request form-check-input" checked="checked" />
<label class="form-check-label" for="create_merge_request-00242ff00f3dec678d597accdf5bb398">Start a <strong>new merge request</strong> with these changes
</label></div>

</div>
</div>
</div>
<input type="hidden" name="original_branch" id="original_branch" value="8c40b964a0ab560f10c089be1f1eb4fa92551a91" class="js-original-branch" />

<div class="form-actions">
<button name="button" type="button" class="btn btn-success btn-upload-file" id="submit-all"><i aria-hidden="true" data-hidden="true" class="fa fa-spin fa-spinner js-loading-icon hidden"></i>
Replace file
</button><a class="btn btn-cancel" data-dismiss="modal" href="#">Cancel</a>

</div>
</form></div>
</div>
</div>
</div>

</div>

</div>
</div>
</div>
</div>




</body>
</html>

