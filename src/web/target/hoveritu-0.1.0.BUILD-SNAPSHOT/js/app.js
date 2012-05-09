var DELAY = 1000;

function update() {
	$.ajax({
		url : "json/state",
		cache : false,
		success : function(data) {
			var state = jQuery.parseJSON(data);
			$("#speed").html(state.speed);
			$("#battery").html(state.batteryLevel);
			$("#pressure").html(state.pressure);
			setTimeout("update()", DELAY);
		}
	});
};