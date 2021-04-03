function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["lab3_step_GM:18"] = "lab3_step_GM.c:188,197";
	/* <Root>/Gc */
	this.urlHashMap["lab3_step_GM:69"] = "lab3_step_GM.c:221,385,498&lab3_step_GM.h:172,177,182,199,202&lab3_step_GM_data.c:26,31";
	/* <Root>/K */
	this.urlHashMap["lab3_step_GM:70"] = "lab3_step_GM.c:215&lab3_step_GM.h:155,226&lab3_step_GM_data.c:56";
	/* <Root>/Sum */
	this.urlHashMap["lab3_step_GM:68"] = "lab3_step_GM.c:216";
	/* <Root>/Transmit to Computer */
	this.urlHashMap["lab3_step_GM:19"] = "lab3_step_GM.c:171,172,196,198,458,471,506,507,513&lab3_step_GM.h:161,165";
	/* <Root>/Voltage
Source */
	this.urlHashMap["lab3_step_GM:20"] = "lab3_step_GM.c:205,213&lab3_step_GM.h:217,220,223&lab3_step_GM_data.c:47,50,53";
	/* <S1>/CPR */
	this.urlHashMap["lab3_step_GM:54"] = "lab3_step_GM.c:164&lab3_step_GM.h:211&lab3_step_GM_data.c:41";
	/* <S1>/Data Type Conversion */
	this.urlHashMap["lab3_step_GM:3"] = "lab3_step_GM.c:166";
	/* <S1>/Encoder */
	this.urlHashMap["lab3_step_GM:4"] = "lab3_step_GM.c:158,347,486&lab3_step_GM.h:156,162,259,262,265&lab3_step_GM_data.c:89,92,95";
	/* <S1>/Product */
	this.urlHashMap["lab3_step_GM:42"] = "lab3_step_GM.c:163";
	/* <S1>/Saturation */
	this.urlHashMap["lab3_step_GM:52"] = "lab3_step_GM.c:229,238&lab3_step_GM.h:229,232&lab3_step_GM_data.c:59,62";
	/* <S1>/min x sampling freq */
	this.urlHashMap["lab3_step_GM:41"] = "lab3_step_GM.c:165&lab3_step_GM.h:208&lab3_step_GM_data.c:38";
	/* <S2>/Abs */
	this.urlHashMap["lab3_step_GM:7"] = "lab3_step_GM.c:274";
	/* <S2>/Clock */
	this.urlHashMap["lab3_step_GM:9"] = "lab3_step_GM.c:275";
	/* <S2>/Gain1 */
	this.urlHashMap["lab3_step_GM:11"] = "lab3_step_GM.c:240&lab3_step_GM.h:235&lab3_step_GM_data.c:65";
	/* <S2>/MATLAB Function */
	this.urlHashMap["lab3_step_GM:12"] = "lab3_step_GM.c:273,288";
	/* <S2>/Saturation */
	this.urlHashMap["lab3_step_GM:14"] = "lab3_step_GM.c:290,301&lab3_step_GM.h:244,247&lab3_step_GM_data.c:74,77";
	/* <S2>/Step */
	this.urlHashMap["lab3_step_GM:15"] = "lab3_step_GM.c:318,326&lab3_step_GM.h:250,253,256&lab3_step_GM_data.c:80,83,86";
	/* <S3>/Data Type Conversion */
	this.urlHashMap["lab3_step_GM:8:11"] = "lab3_step_GM.c:328,339";
	/* <S3>/Digital Output */
	this.urlHashMap["lab3_step_GM:8:12"] = "lab3_step_GM.c:341,342,481,524,525,531&lab3_step_GM.h:164,167";
	/* <S4>/Data Type Conversion */
	this.urlHashMap["lab3_step_GM:10:11"] = "lab3_step_GM.c:255,266";
	/* <S4>/Digital Output */
	this.urlHashMap["lab3_step_GM:10:12"] = "lab3_step_GM.c:268,269,473,515,516,522&lab3_step_GM.h:163,166";
	/* <S5>:1 */
	this.urlHashMap["lab3_step_GM:12:1"] = "lab3_step_GM.c:277";
	/* <S5>:1:3 */
	this.urlHashMap["lab3_step_GM:12:1:3"] = "lab3_step_GM.c:278";
	/* <S5>:1:4 */
	this.urlHashMap["lab3_step_GM:12:1:4"] = "lab3_step_GM.c:280";
	/* <S5>:1:5 */
	this.urlHashMap["lab3_step_GM:12:1:5"] = "lab3_step_GM.c:283";
	/* <S5>:1:6 */
	this.urlHashMap["lab3_step_GM:12:1:6"] = "lab3_step_GM.c:284";
	/* <S6>/Data Type Conversion */
	this.urlHashMap["lab3_step_GM:13:114"] = "lab3_step_GM.c:292,296,303";
	/* <S6>/PWM */
	this.urlHashMap["lab3_step_GM:13:215"] = "lab3_step_GM.c:314,478&lab3_step_GM.h:205&lab3_step_GM_data.c:35";
	/* <S7>/Constant */
	this.urlHashMap["lab3_step_GM:16:269"] = "lab3_step_GM.c:244&lab3_step_GM.h:214&lab3_step_GM_data.c:44";
	/* <S7>/Constant1 */
	this.urlHashMap["lab3_step_GM:16:270"] = "lab3_step_GM.c:245&lab3_step_GM.h:238&lab3_step_GM_data.c:68";
	/* <S7>/Switch */
	this.urlHashMap["lab3_step_GM:16:271"] = "lab3_step_GM.c:243,253&lab3_step_GM.h:241&lab3_step_GM_data.c:71";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "lab3_step_GM"};
	this.sidHashMap["lab3_step_GM"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "lab3_step_GM:1"};
	this.sidHashMap["lab3_step_GM:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "lab3_step_GM:5"};
	this.sidHashMap["lab3_step_GM:5"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "lab3_step_GM:8"};
	this.sidHashMap["lab3_step_GM:8"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "lab3_step_GM:10"};
	this.sidHashMap["lab3_step_GM:10"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "lab3_step_GM:12"};
	this.sidHashMap["lab3_step_GM:12"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "lab3_step_GM:13"};
	this.sidHashMap["lab3_step_GM:13"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "lab3_step_GM:16"};
	this.sidHashMap["lab3_step_GM:16"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<Root>/DC Motor Plant"] = {sid: "lab3_step_GM:1"};
	this.sidHashMap["lab3_step_GM:1"] = {rtwname: "<Root>/DC Motor Plant"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "lab3_step_GM:18"};
	this.sidHashMap["lab3_step_GM:18"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Gc"] = {sid: "lab3_step_GM:69"};
	this.sidHashMap["lab3_step_GM:69"] = {rtwname: "<Root>/Gc"};
	this.rtwnameHashMap["<Root>/K"] = {sid: "lab3_step_GM:70"};
	this.sidHashMap["lab3_step_GM:70"] = {rtwname: "<Root>/K"};
	this.rtwnameHashMap["<Root>/Sum"] = {sid: "lab3_step_GM:68"};
	this.sidHashMap["lab3_step_GM:68"] = {rtwname: "<Root>/Sum"};
	this.rtwnameHashMap["<Root>/Transmit to Computer"] = {sid: "lab3_step_GM:19"};
	this.sidHashMap["lab3_step_GM:19"] = {rtwname: "<Root>/Transmit to Computer"};
	this.rtwnameHashMap["<Root>/Voltage Source"] = {sid: "lab3_step_GM:20"};
	this.sidHashMap["lab3_step_GM:20"] = {rtwname: "<Root>/Voltage Source"};
	this.rtwnameHashMap["<S1>/Voltage (V)"] = {sid: "lab3_step_GM:2"};
	this.sidHashMap["lab3_step_GM:2"] = {rtwname: "<S1>/Voltage (V)"};
	this.rtwnameHashMap["<S1>/CPR"] = {sid: "lab3_step_GM:54"};
	this.sidHashMap["lab3_step_GM:54"] = {rtwname: "<S1>/CPR"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "lab3_step_GM:3"};
	this.sidHashMap["lab3_step_GM:3"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Encoder"] = {sid: "lab3_step_GM:4"};
	this.sidHashMap["lab3_step_GM:4"] = {rtwname: "<S1>/Encoder"};
	this.rtwnameHashMap["<S1>/Motorpwm"] = {sid: "lab3_step_GM:5"};
	this.sidHashMap["lab3_step_GM:5"] = {rtwname: "<S1>/Motorpwm"};
	this.rtwnameHashMap["<S1>/Product"] = {sid: "lab3_step_GM:42"};
	this.sidHashMap["lab3_step_GM:42"] = {rtwname: "<S1>/Product"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "lab3_step_GM:52"};
	this.sidHashMap["lab3_step_GM:52"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/min x sampling freq"] = {sid: "lab3_step_GM:41"};
	this.sidHashMap["lab3_step_GM:41"] = {rtwname: "<S1>/min x sampling freq"};
	this.rtwnameHashMap["<S1>/Velocity (rpm)"] = {sid: "lab3_step_GM:17"};
	this.sidHashMap["lab3_step_GM:17"] = {rtwname: "<S1>/Velocity (rpm)"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "lab3_step_GM:6"};
	this.sidHashMap["lab3_step_GM:6"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/Abs"] = {sid: "lab3_step_GM:7"};
	this.sidHashMap["lab3_step_GM:7"] = {rtwname: "<S2>/Abs"};
	this.rtwnameHashMap["<S2>/Brake"] = {sid: "lab3_step_GM:8"};
	this.sidHashMap["lab3_step_GM:8"] = {rtwname: "<S2>/Brake"};
	this.rtwnameHashMap["<S2>/Clock"] = {sid: "lab3_step_GM:9"};
	this.sidHashMap["lab3_step_GM:9"] = {rtwname: "<S2>/Clock"};
	this.rtwnameHashMap["<S2>/Direction "] = {sid: "lab3_step_GM:10"};
	this.sidHashMap["lab3_step_GM:10"] = {rtwname: "<S2>/Direction "};
	this.rtwnameHashMap["<S2>/Gain1"] = {sid: "lab3_step_GM:11"};
	this.sidHashMap["lab3_step_GM:11"] = {rtwname: "<S2>/Gain1"};
	this.rtwnameHashMap["<S2>/MATLAB Function"] = {sid: "lab3_step_GM:12"};
	this.sidHashMap["lab3_step_GM:12"] = {rtwname: "<S2>/MATLAB Function"};
	this.rtwnameHashMap["<S2>/PWM"] = {sid: "lab3_step_GM:13"};
	this.sidHashMap["lab3_step_GM:13"] = {rtwname: "<S2>/PWM"};
	this.rtwnameHashMap["<S2>/Saturation"] = {sid: "lab3_step_GM:14"};
	this.sidHashMap["lab3_step_GM:14"] = {rtwname: "<S2>/Saturation"};
	this.rtwnameHashMap["<S2>/Step"] = {sid: "lab3_step_GM:15"};
	this.sidHashMap["lab3_step_GM:15"] = {rtwname: "<S2>/Step"};
	this.rtwnameHashMap["<S2>/hardlim"] = {sid: "lab3_step_GM:16"};
	this.sidHashMap["lab3_step_GM:16"] = {rtwname: "<S2>/hardlim"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "lab3_step_GM:8:7"};
	this.sidHashMap["lab3_step_GM:8:7"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/Data Type Conversion"] = {sid: "lab3_step_GM:8:11"};
	this.sidHashMap["lab3_step_GM:8:11"] = {rtwname: "<S3>/Data Type Conversion"};
	this.rtwnameHashMap["<S3>/Digital Output"] = {sid: "lab3_step_GM:8:12"};
	this.sidHashMap["lab3_step_GM:8:12"] = {rtwname: "<S3>/Digital Output"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "lab3_step_GM:10:7"};
	this.sidHashMap["lab3_step_GM:10:7"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/Data Type Conversion"] = {sid: "lab3_step_GM:10:11"};
	this.sidHashMap["lab3_step_GM:10:11"] = {rtwname: "<S4>/Data Type Conversion"};
	this.rtwnameHashMap["<S4>/Digital Output"] = {sid: "lab3_step_GM:10:12"};
	this.sidHashMap["lab3_step_GM:10:12"] = {rtwname: "<S4>/Digital Output"};
	this.rtwnameHashMap["<S5>:1"] = {sid: "lab3_step_GM:12:1"};
	this.sidHashMap["lab3_step_GM:12:1"] = {rtwname: "<S5>:1"};
	this.rtwnameHashMap["<S5>:1:3"] = {sid: "lab3_step_GM:12:1:3"};
	this.sidHashMap["lab3_step_GM:12:1:3"] = {rtwname: "<S5>:1:3"};
	this.rtwnameHashMap["<S5>:1:4"] = {sid: "lab3_step_GM:12:1:4"};
	this.sidHashMap["lab3_step_GM:12:1:4"] = {rtwname: "<S5>:1:4"};
	this.rtwnameHashMap["<S5>:1:5"] = {sid: "lab3_step_GM:12:1:5"};
	this.sidHashMap["lab3_step_GM:12:1:5"] = {rtwname: "<S5>:1:5"};
	this.rtwnameHashMap["<S5>:1:6"] = {sid: "lab3_step_GM:12:1:6"};
	this.sidHashMap["lab3_step_GM:12:1:6"] = {rtwname: "<S5>:1:6"};
	this.rtwnameHashMap["<S6>/In1"] = {sid: "lab3_step_GM:13:116"};
	this.sidHashMap["lab3_step_GM:13:116"] = {rtwname: "<S6>/In1"};
	this.rtwnameHashMap["<S6>/Data Type Conversion"] = {sid: "lab3_step_GM:13:114"};
	this.sidHashMap["lab3_step_GM:13:114"] = {rtwname: "<S6>/Data Type Conversion"};
	this.rtwnameHashMap["<S6>/PWM"] = {sid: "lab3_step_GM:13:215"};
	this.sidHashMap["lab3_step_GM:13:215"] = {rtwname: "<S6>/PWM"};
	this.rtwnameHashMap["<S7>/n"] = {sid: "lab3_step_GM:16:268"};
	this.sidHashMap["lab3_step_GM:16:268"] = {rtwname: "<S7>/n"};
	this.rtwnameHashMap["<S7>/Constant"] = {sid: "lab3_step_GM:16:269"};
	this.sidHashMap["lab3_step_GM:16:269"] = {rtwname: "<S7>/Constant"};
	this.rtwnameHashMap["<S7>/Constant1"] = {sid: "lab3_step_GM:16:270"};
	this.sidHashMap["lab3_step_GM:16:270"] = {rtwname: "<S7>/Constant1"};
	this.rtwnameHashMap["<S7>/Switch"] = {sid: "lab3_step_GM:16:271"};
	this.sidHashMap["lab3_step_GM:16:271"] = {rtwname: "<S7>/Switch"};
	this.rtwnameHashMap["<S7>/a"] = {sid: "lab3_step_GM:16:272"};
	this.sidHashMap["lab3_step_GM:16:272"] = {rtwname: "<S7>/a"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
