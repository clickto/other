package bitc.sz.wzEnv.util;
import java.util.HashMap;
import java.util.Map;

public class ExtjsResponse {
    private boolean success;
    private String message;
    private String title;
    private Map<String, Object> attributes;

    public ExtjsResponse() {
    }

    public ExtjsResponse(boolean success) {
        this();
        this.success = success;
    }

    public ExtjsResponse(boolean success, String title, String message) {
        this();
        this.success = success;
        this.message = message;
        this.title = title;
    }

    public void addAttribute(String key, Object value) {
        if (attributes == null) {
            attributes = new HashMap<String, Object>();
        }
        attributes.put(key, value);
    }

    public boolean isSuccess() {
        return success;
    }

    public void setSuccess(boolean success) {
        this.success = success;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public Map<String, Object> getAttributes() {
        return attributes;
    }

    public void setAttributes(Map<String, Object> attributes) {
        this.attributes = attributes;
    }

    @Override
    public String toString() {
        return JsonUtil.getJsonString(this);
    }
}