var DELAY = 1000;

function update() {
	$.ajax({
		url : "json/state",
		cache : false,
		success : function(data) {
			var state = jQuery.parseJSON(data);
			$("#speed").html(state.speed);
			$("#battery").html(state.batteryLevel);
			$("#pressure").html(state.pressure.toFixed(3));
			$("#longitude").html(state.longitude.toFixed(3));
			$("#latitude").html(state.latitude.toFixed(3));
			setTimeout("update()", DELAY);
		}
	});
};

function update_post() {
	$.ajax({
		type: 'POST',
		url : "json/state",
		cache : false,
		success : function(data) {
			var state = jQuery.parseJSON(data);
			$("#speed").html(state.speed);
			$("#battery").html(state.batteryLevel);
			$("#pressure").html(state.pressure.toFixed(3));
			$("#longitude").html(state.longitude.toFixed(3));
			$("#latitude").html(state.latitude.toFixed(3));
			setTimeout("update()", DELAY);
		}
	});
};