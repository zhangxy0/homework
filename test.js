function judge(rows,tbody,flag,header){
	$("th").removeClass();
	if(flag){
		rows.reverse();
		header.addClass("descend");
    }
	else header.addClass("ascend");
	for(var i=0;i<rows.length;i++)
		tbody.appendChild(rows[i]);
}

function makeTableSortable(table){
	var headers=table.getElementsByTagName("th");
    for(var i=0;i<headers.length;i++){
        (function(n){
            var flag=false;
            headers[n].onclick=function(){
                var tbody=table.tBodies[0];
                var rows=tbody.getElementsByTagName("tr");
                rows=Array.prototype.slice.call(rows,0);
                rows.sort(function(row1,row2){
                    var val1=row1.getElementsByTagName("td")[n].textContent||row1.getElementsByTagName("td")[n].innerText;
                    var val2=row2.getElementsByTagName("td")[n].textContent||row2.getElementsByTagName("td")[n].innerText;
                    if(val1<val2) return -1;
                    else if(val1>val2) return 1;
					else return 0;
				});
				judge(rows,tbody,flag,$(this));
				flag=!flag;
            }
        }(i));
    }
}
window.onload=function(){
    var tables=document.getElementsByTagName("table");
	for (var j = 0; j < tables.length; j ++){
		makeTableSortable(tables[j]);
	}
}
