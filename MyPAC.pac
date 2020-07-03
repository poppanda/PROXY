function FindProxyForURL(url, host)
{
    url  = url.toLowerCase();
    host = host.toLowerCase();
    proxy = "PROXY 192.168.31.155:8787; DIRECT";

    if (shExpMatch(url,"*twitter*")  ||
        shExpMatch(url,"*facebook*") ||
        shExpMatch(url,"*fb*") ||
        shExpMatch(url,"*messenger*")) {
	        return proxy;
		};
	
    if (shExpMatch(url,"*youtube*") ||
        shExpMatch(url,"*google*")){
	        return proxy;
		};
		
    if (shExpMatch(url,"*wikipedia*") ||
        shExpMatch(url,"*blogspot*")
       ){
        return proxy;
    }
    return "DIRECT";
}