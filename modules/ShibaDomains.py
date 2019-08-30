# Domains for Shibemail

class IPAddress:
    # Validates an IP address
    @staticmethod
    def validateIP(ipaddr):
        if type(ipaddr) is str:
            ipvector = ipaddr.split(".")
            for numstr in ipvector:
                num = int(numstr)
                if num>255 or num<0:
                    raise Exception("This Ip address doesn't exist: {}".format(ipaddr))
                    return 0
            return 1
        else:   
            raise Exception("Ip address must be passed as string!")
            return 0

    @staticmethod
    def validatePort(port):
        if port>65535 or port<0:
            raise Exception("Invalid port number!")
            