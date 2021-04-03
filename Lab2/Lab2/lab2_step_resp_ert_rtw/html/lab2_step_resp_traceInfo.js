function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["lab2_step_resp:18"] = "lab2_step_resp.c:83,98";
	/* <Root>/Transmit to Computer */
	this.urlHashMap["lab2_step_resp:19"] = "lab2_step_resp.c:66,67,97,99,297,310,342,343,349&lab2_step_resp.h:60,64";
	/* <Root>/Voltage
Source */
	this.urlHashMap["lab2_step_resp:20"] = "lab2_step_resp.c:106,114&lab2_step_resp.h:87,90,93&lab2_step_resp_data.c:41,44,47";
	/* <S1>/CPR */
	this.urlHashMap["lab2_step_resp:54"] = "lab2_step_resp.c:84&lab2_step_resp.h:84&lab2_step_resp_data.c:38";
	/* <S1>/Data Type Conversion */
	this.urlHashMap["lab2_step_resp:3"] = "lab2_step_resp.c:86";
	/* <S1>/Encoder */
	this.urlHashMap["lab2_step_resp:4"] = "lab2_step_resp.c:61,231,325&lab2_step_resp.h:55,61,123,126,129&lab2_step_resp_data.c:77,80,83";
	/* <S1>/Product */
	this.urlHashMap["lab2_step_resp:42"] = "lab2_step_resp.c:87";
	/* <S1>/Saturation */
	this.urlHashMap["lab2_step_resp:52"] = "lab2_step_resp.c:116,125&lab2_step_resp.h:96,99&lab2_step_resp_data.c:50,53";
	/* <S1>/min x sampling freq */
	this.urlHashMap["lab2_step_resp:41"] = "lab2_step_resp.c:85&lab2_step_resp.h:81&lab2_step_resp_data.c:35";
	/* <S2>/Abs */
	this.urlHashMap["lab2_step_resp:7"] = "lab2_step_resp.c:161";
	/* <S2>/Clock */
	this.urlHashMap["lab2_step_resp:9"] = "lab2_step_resp.c:162";
	/* <S2>/Gain1 */
	this.urlHashMap["lab2_step_resp:11"] = "lab2_step_resp.c:127&lab2_step_resp.h:102&lab2_step_resp_data.c:56";
	/* <S2>/MATLAB Function */
	this.urlHashMap["lab2_step_resp:12"] = "lab2_step_resp.c:160,175";
	/* <S2>/Saturation */
	this.urlHashMap["lab2_step_resp:14"] = "lab2_step_resp.c:177,188&lab2_step_resp.h:108,111&lab2_step_resp_data.c:62,65";
	/* <S2>/Step */
	this.urlHashMap["lab2_step_resp:15"] = "lab2_step_resp.c:204,211&lab2_step_resp.h:114,117,120&lab2_step_resp_data.c:68,71,74";
	/* <S3>/Data Type Conversion */
	this.urlHashMap["lab2_step_resp:8:11"] = "lab2_step_resp.c:213,224";
	/* <S3>/Digital Output */
	this.urlHashMap["lab2_step_resp:8:12"] = "lab2_step_resp.c:226,227,320,360,361,367&lab2_step_resp.h:63,66";
	/* <S4>/Data Type Conversion */
	this.urlHashMap["lab2_step_resp:10:11"] = "lab2_step_resp.c:142,153";
	/* <S4>/Digital Output */
	this.urlHashMap["lab2_step_resp:10:12"] = "lab2_step_resp.c:155,156,312,351,352,358&lab2_step_resp.h:62,65";
	/* <S5>:1 */
	this.urlHashMap["lab2_step_resp:12:1"] = "lab2_step_resp.c:164";
	/* <S5>:1:3 */
	this.urlHashMap["lab2_step_resp:12:1:3"] = "lab2_step_resp.c:165";
	/* <S5>:1:4 */
	this.urlHashMap["lab2_step_resp:12:1:4"] = "lab2_step_resp.c:167";
	/* <S5>:1:5 */
	this.urlHashMap["lab2_step_resp:12:1:5"] = "lab2_step_resp.c:170";
	/* <S5>:1:6 */
	this.urlHashMap["lab2_step_resp:12:1:6"] = "lab2_step_resp.c:171";
	/* <S6>/Data Type Conversion */
	this.urlHashMap["lab2_step_resp:13:114"] = "lab2_step_resp.c:179,183,190";
	/* <S6>/PWM */
	this.urlHashMap["lab2_step_resp:13:215"] = "lab2_step_resp.c:201,317&lab2_step_resp.h:72&lab2_step_resp_data.c:26";
	/* <S7>/Constant */
	this.urlHashMap["lab2_step_resp:16:269"] = "lab2_step_resp.c:131&lab2_step_resp.h:78&lab2_step_resp_data.c:32";
	/* <S7>/Constant1 */
	this.urlHashMap["lab2_step_resp:16:270"] = "lab2_step_resp.c:132&lab2_step_resp.h:75&lab2_step_resp_data.c:29";
	/* <S7>/Switch */
	this.urlHashMap["lab2_step_resp:16:271"] = "lab2_step_resp.c:130,140&lab2_step_resp.h:105&lab2_step_resp_data.c:59";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "lab2_step_resp"};
	this.sidHashMap["lab2_step_resp"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "lab2_step_resp:1"};
	this.sidHashMap["lab2_step_resp:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "lab2_step_resp:5"};
	this.sidHashMap["lab2_step_resp:5"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "lab2_step_resp:8"};
	this.sidHashMap["lab2_step_resp:8"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "lab2_step_resp:10"};
	this.sidHashMap["lab2_step_resp:10"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "lab2_step_resp:12"};
	this.sidHashMap["lab2_step_resp:12"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "lab2_step_resp:13"};
	this.sidHashMap["lab2_step_resp:13"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "lab2_step_resp:16"};
	this.sidHashMap["lab2_step_resp:16"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<Root>/DC Motor Plant"] = {sid: "lab2_step_resp:1"};
	this.sidHashMap["lab2_step_resp:1"] = {rtwname: "<Root>/DC Motor Plant"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "lab2_step_resp:18"};
	this.sidHashMap["lab2_step_resp:18"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Transmit to Computer"] = {sid: "lab2_step_resp:19"};
	this.sidHashMap["lab2_step_resp:19"] = {rtwname: "<Root>/Transmit to Computer"};
	this.rtwnameHashMap["<Root>/Voltage Source"] = {sid: "lab2_step_resp:20"};
	this.sidHashMap["lab2_step_resp:20"] = {rtwname: "<Root>/Voltage Source"};
	this.rtwnameHashMap["<S1>/Voltage (V)"] = {sid: "lab2_step_resp:2"};
	this.sidHashMap["lab2_step_resp:2"] = {rtwname: "<S1>/Voltage (V)"};
	this.rtwnameHashMap["<S1>/CPR"] = {sid: "lab2_step_resp:54"};
	this.sidHashMap["lab2_step_resp:54"] = {rtwname: "<S1>/CPR"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "lab2_step_resp:3"};
	this.sidHashMap["lab2_step_resp:3"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Encoder"] = {sid: "lab2_step_resp:4"};
	this.sidHashMap["lab2_step_resp:4"] = {rtwname: "<S1>/Encoder"};
	this.rtwnameHashMap["<S1>/Motorpwm"] = {sid: "lab2_step_resp:5"};
	this.sidHashMap["lab2_step_resp:5"] = {rtwname: "<S1>/Motorpwm"};
	this.rtwnameHashMap["<S1>/Product"] = {sid: "lab2_step_resp:42"};
	this.sidHashMap["lab2_step_resp:42"] = {rtwname: "<S1>/Product"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "lab2_step_resp:52"};
	this.sidHashMap["lab2_step_resp:52"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/min x sampling freq"] = {sid: "lab2_step_resp:41"};
	this.sidHashMap["lab2_step_resp:41"] = {rtwname: "<S1>/min x sampling freq"};
	this.rtwnameHashMap["<S1>/Velocity (rpm)"] = {sid: "lab2_step_resp:17"};
	this.sidHashMap["lab2_step_resp:17"] = {rtwname: "<S1>/Velocity (rpm)"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "lab2_step_resp:6"};
	this.sidHashMap["lab2_step_resp:6"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/Abs"] = {sid: "lab2_step_resp:7"};
	this.sidHashMap["lab2_step_resp:7"] = {rtwname: "<S2>/Abs"};
	this.rtwnameHashMap["<S2>/Brake"] = {sid: "lab2_step_resp:8"};
	this.sidHashMap["lab2_step_resp:8"] = {rtwname: "<S2>/Brake"};
	this.rtwnameHashMap["<S2>/Clock"] = {sid: "lab2_step_resp:9"};
	this.sidHashMap["lab2_step_resp:9"] = {rtwname: "<S2>/Clock"};
	this.rtwnameHashMap["<S2>/Direction "] = {sid: "lab2_step_resp:10"};
	this.sidHashMap["lab2_step_resp:10"] = {rtwname: "<S2>/Direction "};
	this.rtwnameHashMap["<S2>/Gain1"] = {sid: "lab2_step_resp:11"};
	this.sidHashMap["lab2_step_resp:11"] = {rtwname: "<S2>/Gain1"};
	this.rtwnameHashMap["<S2>/MATLAB Function"] = {sid: "lab2_step_resp:12"};
	this.sidHashMap["lab2_step_resp:12"] = {rtwname: "<S2>/MATLAB Function"};
	this.rtwnameHashMap["<S2>/PWM"] = {sid: "lab2_step_resp:13"};
	this.sidHashMap["lab2_step_resp:13"] = {rtwname: "<S2>/PWM"};
	this.rtwnameHashMap["<S2>/Saturation"] = {sid: "lab2_step_resp:14"};
	this.sidHashMap["lab2_step_resp:14"] = {rtwname: "<S2>/Saturation"};
	this.rtwnameHashMap["<S2>/Step"] = {sid: "lab2_step_resp:15"};
	this.sidHashMap["lab2_step_resp:15"] = {rtwname: "<S2>/Step"};
	this.rtwnameHashMap["<S2>/hardlim"] = {sid: "lab2_step_resp:16"};
	this.sidHashMap["lab2_step_resp:16"] = {rtwname: "<S2>/hardlim"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "lab2_step_resp:8:7"};
	this.sidHashMap["lab2_step_resp:8:7"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/Data Type Conversion"] = {sid: "lab2_step_resp:8:11"};
	this.sidHashMap["lab2_step_resp:8:11"] = {rtwname: "<S3>/Data Type Conversion"};
	this.rtwnameHashMap["<S3>/Digital Output"] = {sid: "lab2_step_resp:8:12"};
	this.sidHashMap["lab2_step_resp:8:12"] = {rtwname: "<S3>/Digital Output"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "lab2_step_resp:10:7"};
	this.sidHashMap["lab2_step_resp:10:7"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/Data Type Conversion"] = {sid: "lab2_step_resp:10:11"};
	this.sidHashMap["lab2_step_resp:10:11"] = {rtwname: "<S4>/Data Type Conversion"};
	this.rtwnameHashMap["<S4>/Digital Output"] = {sid: "lab2_step_resp:10:12"};
	this.sidHashMap["lab2_step_resp:10:12"] = {rtwname: "<S4>/Digital Output"};
	this.rtwnameHashMap["<S5>:1"] = {sid: "lab2_step_resp:12:1"};
	this.sidHashMap["lab2_step_resp:12:1"] = {rtwname: "<S5>:1"};
	this.rtwnameHashMap["<S5>:1:3"] = {sid: "lab2_step_resp:12:1:3"};
	this.sidHashMap["lab2_step_resp:12:1:3"] = {rtwname: "<S5>:1:3"};
	this.rtwnameHashMap["<S5>:1:4"] = {sid: "lab2_step_resp:12:1:4"};
	this.sidHashMap["lab2_step_resp:12:1:4"] = {rtwname: "<S5>:1:4"};
	this.rtwnameHashMap["<S5>:1:5"] = {sid: "lab2_step_resp:12:1:5"};
	this.sidHashMap["lab2_step_resp:12:1:5"] = {rtwname: "<S5>:1:5"};
	this.rtwnameHashMap["<S5>:1:6"] = {sid: "lab2_step_resp:12:1:6"};
	this.sidHashMap["lab2_step_resp:12:1:6"] = {rtwname: "<S5>:1:6"};
	this.rtwnameHashMap["<S6>/In1"] = {sid: "lab2_step_resp:13:116"};
	this.sidHashMap["lab2_step_resp:13:116"] = {rtwname: "<S6>/In1"};
	this.rtwnameHashMap["<S6>/Data Type Conversion"] = {sid: "lab2_step_resp:13:114"};
	this.sidHashMap["lab2_step_resp:13:114"] = {rtwname: "<S6>/Data Type Conversion"};
	this.rtwnameHashMap["<S6>/PWM"] = {sid: "lab2_step_resp:13:215"};
	this.sidHashMap["lab2_step_resp:13:215"] = {rtwname: "<S6>/PWM"};
	this.rtwnameHashMap["<S7>/n"] = {sid: "lab2_step_resp:16:268"};
	this.sidHashMap["lab2_step_resp:16:268"] = {rtwname: "<S7>/n"};
	this.rtwnameHashMap["<S7>/Constant"] = {sid: "lab2_step_resp:16:269"};
	this.sidHashMap["lab2_step_resp:16:269"] = {rtwname: "<S7>/Constant"};
	this.rtwnameHashMap["<S7>/Constant1"] = {sid: "lab2_step_resp:16:270"};
	this.sidHashMap["lab2_step_resp:16:270"] = {rtwname: "<S7>/Constant1"};
	this.rtwnameHashMap["<S7>/Switch"] = {sid: "lab2_step_resp:16:271"};
	this.sidHashMap["lab2_step_resp:16:271"] = {rtwname: "<S7>/Switch"};
	this.rtwnameHashMap["<S7>/a"] = {sid: "lab2_step_resp:16:272"};
	this.sidHashMap["lab2_step_resp:16:272"] = {rtwname: "<S7>/a"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
