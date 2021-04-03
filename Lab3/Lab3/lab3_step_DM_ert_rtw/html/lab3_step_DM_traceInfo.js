function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["lab3_step_DM:22"] = "lab3_step_DM.c:378,387";
	/* <Root>/Gc */
	this.urlHashMap["lab3_step_DM:23"] = "lab3_step_DM.c:422,609,734&lab3_step_DM.h:190,195,200,217,220&lab3_step_DM_data.c:26,31";
	/* <Root>/Sum */
	this.urlHashMap["lab3_step_DM:25"] = "lab3_step_DM.c:419&lab3_step_DM.h:158";
	/* <Root>/Time Delay */
	this.urlHashMap["lab3_step_DM:28"] = "lab3_step_DM.c:341,547,681&lab3_step_DM.h:169,173,185,226,229&lab3_step_DM_data.c:38,41";
	/* <Root>/Transmit to Computer */
	this.urlHashMap["lab3_step_DM:26"] = "lab3_step_DM.c:361,362,386,388,694,707,742,743,749&lab3_step_DM.h:164,177";
	/* <Root>/Voltage
Source */
	this.urlHashMap["lab3_step_DM:27"] = "lab3_step_DM.c:408,416&lab3_step_DM.h:157,241,244,247&lab3_step_DM_data.c:53,56,59";
	/* <S1>/CPR */
	this.urlHashMap["lab3_step_DM:3"] = "lab3_step_DM.c:401&lab3_step_DM.h:232&lab3_step_DM_data.c:44";
	/* <S1>/Data Type Conversion */
	this.urlHashMap["lab3_step_DM:4"] = "lab3_step_DM.c:403";
	/* <S1>/Encoder */
	this.urlHashMap["lab3_step_DM:5"] = "lab3_step_DM.c:395,571,722&lab3_step_DM.h:159,165,280,283,286&lab3_step_DM_data.c:92,95,98";
	/* <S1>/Product */
	this.urlHashMap["lab3_step_DM:18"] = "lab3_step_DM.c:400&lab3_step_DM.h:156";
	/* <S1>/Saturation */
	this.urlHashMap["lab3_step_DM:19"] = "lab3_step_DM.c:431,440&lab3_step_DM.h:250,253&lab3_step_DM_data.c:62,65";
	/* <S1>/min x sampling freq */
	this.urlHashMap["lab3_step_DM:20"] = "lab3_step_DM.c:402&lab3_step_DM.h:235&lab3_step_DM_data.c:47";
	/* <S2>/Abs */
	this.urlHashMap["lab3_step_DM:8"] = "lab3_step_DM.c:476";
	/* <S2>/Clock */
	this.urlHashMap["lab3_step_DM:10"] = "lab3_step_DM.c:477";
	/* <S2>/Gain1 */
	this.urlHashMap["lab3_step_DM:12"] = "lab3_step_DM.c:442&lab3_step_DM.h:256&lab3_step_DM_data.c:68";
	/* <S2>/MATLAB Function */
	this.urlHashMap["lab3_step_DM:13"] = "lab3_step_DM.c:475,490";
	/* <S2>/Saturation */
	this.urlHashMap["lab3_step_DM:15"] = "lab3_step_DM.c:492,503&lab3_step_DM.h:265,268&lab3_step_DM_data.c:77,80";
	/* <S2>/Step */
	this.urlHashMap["lab3_step_DM:16"] = "lab3_step_DM.c:520,527&lab3_step_DM.h:271,274,277&lab3_step_DM_data.c:83,86,89";
	/* <S3>/Data Type Conversion */
	this.urlHashMap["lab3_step_DM:9:11"] = "lab3_step_DM.c:529,540";
	/* <S3>/Digital Output */
	this.urlHashMap["lab3_step_DM:9:12"] = "lab3_step_DM.c:542,543,717,760,761,767&lab3_step_DM.h:176,179";
	/* <S4>/Data Type Conversion */
	this.urlHashMap["lab3_step_DM:11:11"] = "lab3_step_DM.c:457,468";
	/* <S4>/Digital Output */
	this.urlHashMap["lab3_step_DM:11:12"] = "lab3_step_DM.c:470,471,709,751,752,758&lab3_step_DM.h:175,178";
	/* <S5>:1 */
	this.urlHashMap["lab3_step_DM:13:1"] = "lab3_step_DM.c:479";
	/* <S5>:1:3 */
	this.urlHashMap["lab3_step_DM:13:1:3"] = "lab3_step_DM.c:480";
	/* <S5>:1:4 */
	this.urlHashMap["lab3_step_DM:13:1:4"] = "lab3_step_DM.c:482";
	/* <S5>:1:5 */
	this.urlHashMap["lab3_step_DM:13:1:5"] = "lab3_step_DM.c:485";
	/* <S5>:1:6 */
	this.urlHashMap["lab3_step_DM:13:1:6"] = "lab3_step_DM.c:486";
	/* <S6>/Data Type Conversion */
	this.urlHashMap["lab3_step_DM:14:114"] = "lab3_step_DM.c:494,498,505";
	/* <S6>/PWM */
	this.urlHashMap["lab3_step_DM:14:215"] = "lab3_step_DM.c:516,714&lab3_step_DM.h:223&lab3_step_DM_data.c:35";
	/* <S7>/Constant */
	this.urlHashMap["lab3_step_DM:17:269"] = "lab3_step_DM.c:446&lab3_step_DM.h:238&lab3_step_DM_data.c:50";
	/* <S7>/Constant1 */
	this.urlHashMap["lab3_step_DM:17:270"] = "lab3_step_DM.c:447&lab3_step_DM.h:259&lab3_step_DM_data.c:71";
	/* <S7>/Switch */
	this.urlHashMap["lab3_step_DM:17:271"] = "lab3_step_DM.c:445,455&lab3_step_DM.h:262&lab3_step_DM_data.c:74";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "lab3_step_DM"};
	this.sidHashMap["lab3_step_DM"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "lab3_step_DM:1"};
	this.sidHashMap["lab3_step_DM:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "lab3_step_DM:6"};
	this.sidHashMap["lab3_step_DM:6"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "lab3_step_DM:9"};
	this.sidHashMap["lab3_step_DM:9"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "lab3_step_DM:11"};
	this.sidHashMap["lab3_step_DM:11"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "lab3_step_DM:13"};
	this.sidHashMap["lab3_step_DM:13"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "lab3_step_DM:14"};
	this.sidHashMap["lab3_step_DM:14"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "lab3_step_DM:17"};
	this.sidHashMap["lab3_step_DM:17"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<Root>/DC Motor Plant"] = {sid: "lab3_step_DM:1"};
	this.sidHashMap["lab3_step_DM:1"] = {rtwname: "<Root>/DC Motor Plant"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "lab3_step_DM:22"};
	this.sidHashMap["lab3_step_DM:22"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Gc"] = {sid: "lab3_step_DM:23"};
	this.sidHashMap["lab3_step_DM:23"] = {rtwname: "<Root>/Gc"};
	this.rtwnameHashMap["<Root>/Sum"] = {sid: "lab3_step_DM:25"};
	this.sidHashMap["lab3_step_DM:25"] = {rtwname: "<Root>/Sum"};
	this.rtwnameHashMap["<Root>/Time Delay"] = {sid: "lab3_step_DM:28"};
	this.sidHashMap["lab3_step_DM:28"] = {rtwname: "<Root>/Time Delay"};
	this.rtwnameHashMap["<Root>/Transmit to Computer"] = {sid: "lab3_step_DM:26"};
	this.sidHashMap["lab3_step_DM:26"] = {rtwname: "<Root>/Transmit to Computer"};
	this.rtwnameHashMap["<Root>/Voltage Source"] = {sid: "lab3_step_DM:27"};
	this.sidHashMap["lab3_step_DM:27"] = {rtwname: "<Root>/Voltage Source"};
	this.rtwnameHashMap["<S1>/Voltage (V)"] = {sid: "lab3_step_DM:2"};
	this.sidHashMap["lab3_step_DM:2"] = {rtwname: "<S1>/Voltage (V)"};
	this.rtwnameHashMap["<S1>/CPR"] = {sid: "lab3_step_DM:3"};
	this.sidHashMap["lab3_step_DM:3"] = {rtwname: "<S1>/CPR"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "lab3_step_DM:4"};
	this.sidHashMap["lab3_step_DM:4"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Encoder"] = {sid: "lab3_step_DM:5"};
	this.sidHashMap["lab3_step_DM:5"] = {rtwname: "<S1>/Encoder"};
	this.rtwnameHashMap["<S1>/Motorpwm"] = {sid: "lab3_step_DM:6"};
	this.sidHashMap["lab3_step_DM:6"] = {rtwname: "<S1>/Motorpwm"};
	this.rtwnameHashMap["<S1>/Product"] = {sid: "lab3_step_DM:18"};
	this.sidHashMap["lab3_step_DM:18"] = {rtwname: "<S1>/Product"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "lab3_step_DM:19"};
	this.sidHashMap["lab3_step_DM:19"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/min x sampling freq"] = {sid: "lab3_step_DM:20"};
	this.sidHashMap["lab3_step_DM:20"] = {rtwname: "<S1>/min x sampling freq"};
	this.rtwnameHashMap["<S1>/Velocity (rpm)"] = {sid: "lab3_step_DM:21"};
	this.sidHashMap["lab3_step_DM:21"] = {rtwname: "<S1>/Velocity (rpm)"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "lab3_step_DM:7"};
	this.sidHashMap["lab3_step_DM:7"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/Abs"] = {sid: "lab3_step_DM:8"};
	this.sidHashMap["lab3_step_DM:8"] = {rtwname: "<S2>/Abs"};
	this.rtwnameHashMap["<S2>/Brake"] = {sid: "lab3_step_DM:9"};
	this.sidHashMap["lab3_step_DM:9"] = {rtwname: "<S2>/Brake"};
	this.rtwnameHashMap["<S2>/Clock"] = {sid: "lab3_step_DM:10"};
	this.sidHashMap["lab3_step_DM:10"] = {rtwname: "<S2>/Clock"};
	this.rtwnameHashMap["<S2>/Direction "] = {sid: "lab3_step_DM:11"};
	this.sidHashMap["lab3_step_DM:11"] = {rtwname: "<S2>/Direction "};
	this.rtwnameHashMap["<S2>/Gain1"] = {sid: "lab3_step_DM:12"};
	this.sidHashMap["lab3_step_DM:12"] = {rtwname: "<S2>/Gain1"};
	this.rtwnameHashMap["<S2>/MATLAB Function"] = {sid: "lab3_step_DM:13"};
	this.sidHashMap["lab3_step_DM:13"] = {rtwname: "<S2>/MATLAB Function"};
	this.rtwnameHashMap["<S2>/PWM"] = {sid: "lab3_step_DM:14"};
	this.sidHashMap["lab3_step_DM:14"] = {rtwname: "<S2>/PWM"};
	this.rtwnameHashMap["<S2>/Saturation"] = {sid: "lab3_step_DM:15"};
	this.sidHashMap["lab3_step_DM:15"] = {rtwname: "<S2>/Saturation"};
	this.rtwnameHashMap["<S2>/Step"] = {sid: "lab3_step_DM:16"};
	this.sidHashMap["lab3_step_DM:16"] = {rtwname: "<S2>/Step"};
	this.rtwnameHashMap["<S2>/hardlim"] = {sid: "lab3_step_DM:17"};
	this.sidHashMap["lab3_step_DM:17"] = {rtwname: "<S2>/hardlim"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "lab3_step_DM:9:7"};
	this.sidHashMap["lab3_step_DM:9:7"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/Data Type Conversion"] = {sid: "lab3_step_DM:9:11"};
	this.sidHashMap["lab3_step_DM:9:11"] = {rtwname: "<S3>/Data Type Conversion"};
	this.rtwnameHashMap["<S3>/Digital Output"] = {sid: "lab3_step_DM:9:12"};
	this.sidHashMap["lab3_step_DM:9:12"] = {rtwname: "<S3>/Digital Output"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "lab3_step_DM:11:7"};
	this.sidHashMap["lab3_step_DM:11:7"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/Data Type Conversion"] = {sid: "lab3_step_DM:11:11"};
	this.sidHashMap["lab3_step_DM:11:11"] = {rtwname: "<S4>/Data Type Conversion"};
	this.rtwnameHashMap["<S4>/Digital Output"] = {sid: "lab3_step_DM:11:12"};
	this.sidHashMap["lab3_step_DM:11:12"] = {rtwname: "<S4>/Digital Output"};
	this.rtwnameHashMap["<S5>:1"] = {sid: "lab3_step_DM:13:1"};
	this.sidHashMap["lab3_step_DM:13:1"] = {rtwname: "<S5>:1"};
	this.rtwnameHashMap["<S5>:1:3"] = {sid: "lab3_step_DM:13:1:3"};
	this.sidHashMap["lab3_step_DM:13:1:3"] = {rtwname: "<S5>:1:3"};
	this.rtwnameHashMap["<S5>:1:4"] = {sid: "lab3_step_DM:13:1:4"};
	this.sidHashMap["lab3_step_DM:13:1:4"] = {rtwname: "<S5>:1:4"};
	this.rtwnameHashMap["<S5>:1:5"] = {sid: "lab3_step_DM:13:1:5"};
	this.sidHashMap["lab3_step_DM:13:1:5"] = {rtwname: "<S5>:1:5"};
	this.rtwnameHashMap["<S5>:1:6"] = {sid: "lab3_step_DM:13:1:6"};
	this.sidHashMap["lab3_step_DM:13:1:6"] = {rtwname: "<S5>:1:6"};
	this.rtwnameHashMap["<S6>/In1"] = {sid: "lab3_step_DM:14:116"};
	this.sidHashMap["lab3_step_DM:14:116"] = {rtwname: "<S6>/In1"};
	this.rtwnameHashMap["<S6>/Data Type Conversion"] = {sid: "lab3_step_DM:14:114"};
	this.sidHashMap["lab3_step_DM:14:114"] = {rtwname: "<S6>/Data Type Conversion"};
	this.rtwnameHashMap["<S6>/PWM"] = {sid: "lab3_step_DM:14:215"};
	this.sidHashMap["lab3_step_DM:14:215"] = {rtwname: "<S6>/PWM"};
	this.rtwnameHashMap["<S7>/n"] = {sid: "lab3_step_DM:17:268"};
	this.sidHashMap["lab3_step_DM:17:268"] = {rtwname: "<S7>/n"};
	this.rtwnameHashMap["<S7>/Constant"] = {sid: "lab3_step_DM:17:269"};
	this.sidHashMap["lab3_step_DM:17:269"] = {rtwname: "<S7>/Constant"};
	this.rtwnameHashMap["<S7>/Constant1"] = {sid: "lab3_step_DM:17:270"};
	this.sidHashMap["lab3_step_DM:17:270"] = {rtwname: "<S7>/Constant1"};
	this.rtwnameHashMap["<S7>/Switch"] = {sid: "lab3_step_DM:17:271"};
	this.sidHashMap["lab3_step_DM:17:271"] = {rtwname: "<S7>/Switch"};
	this.rtwnameHashMap["<S7>/a"] = {sid: "lab3_step_DM:17:272"};
	this.sidHashMap["lab3_step_DM:17:272"] = {rtwname: "<S7>/a"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
