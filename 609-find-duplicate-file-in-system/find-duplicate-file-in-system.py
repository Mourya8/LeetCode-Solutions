class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        content_dict={}
        files=[]
        for i in paths:
            temp=i.split(" ")
            for j in range(1,len(temp)):
                start = temp[j].find('(') + 1
                end = temp[j].find(')')
                s = temp[j][start:end]
                period_pos=temp[j].find('(')
                file_name = temp[j][:period_pos]
                path =temp[0]+"/"+file_name
                if s in content_dict:
                    content_dict[s].append(path)
                else:
                    content_dict[s]=[path]
        result=[]
        for i in content_dict.values():
            if len(i)>1:
                result.append(i)
        
        return result


        