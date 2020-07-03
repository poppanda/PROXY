var proxy = "PROXY 192.168.31.155:8787; DIRECT";

function FindProxyForURL(url, host)
{
    url  = url.toLowerCase();
    host = host.toLowerCase();

    if (shExpMatch(url,"*twitter*")  ||
        shExpMatch(url,"*facebook*") ||
        shExpMatch(url,"*fb*") ||
        shExpMatch(url,"*messenger*")) {
	        return proxy;
		};
	
    if (shExpMatch(url,"*youtube*") ||
        shExpMatch(url,"*google*") ||
        shExpMatch(url,"*stack")){
	        return proxy;
		};
		
    if (shExpMatch(url,"*wikipedia*") ||
        shExpMatch(url,"*blogspot*")
       ){
        return proxy;
    }
    return "DIRECT";
}