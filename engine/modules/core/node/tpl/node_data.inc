[INPUT|id=edit_action|type=hidden|required|name=action|value={SHADOW:context}:node-data-form]
[INPUT|type=hidden|title=path|disabled|id=edit_path|required|name=edit-path|value={ATTRIBUTE|name=name|no_qtags}:node-data-form]
[INPUT|name=redirect|type=hidden|value={SHADOW:redirect}:node-data-form]
[INPUT|id=tmp_files_dir|type=hidden|required|name=tmp_files_dir|value={ATTRIBUTE|name=tmp_files_dir|no_qtags}:node-data-form]
[FORM:node-data-form]
<!-- File plugin -->
<script src="/engine/modules/core/file/js/jquery.knob.js?refresh=[DOCTOR_TIMESTAMP]"></script>
<script src="/engine/modules/core/file/js/jquery.iframe-transport.js?refresh=[DOCTOR_TIMESTAMP]"></script>
<script src="/engine/modules/core/file/js/jquery.fileupload.js?refresh=[DOCTOR_TIMESTAMP]"></script>
<script src="/engine/modules/core/file/js/file-upload.js?refresh=[DOCTOR_TIMESTAMP]"></script>
test
<!-- Froala plugin -->
[CSS|runlast|module=wysiwyg:froala/css/froala_style.min.css]
[CSS|runlast|module=wysiwyg:froala/css/froala_editor.min.css]
[JS|inline|runlast|module=wysiwyg:froala/js/froala_editor.min.js]
[JS|inline|runlast|module=wysiwyg:froala/plugins/paragraph_style.min.js]
[JS|inline|runlast|module=wysiwyg:froala/plugins/paragraph_format.min.js]
[JS|inline|runlast|module=wysiwyg:froala/plugins/link.min.js]
[JS|inline|runlast|module=wysiwyg:froala/plugins/lists.min.js]
[CSS|runlast|module=wysiwyg:froala/plugins/table.css]
[JS|inline|runlast|module=wysiwyg:froala/plugins/table.min.js]
[JS|inline|runlast|module=wysiwyg:froala/plugins/align.min.js]
[CSS|inline|runlast|module=wysiwyg:froala/plugins/line_breaker.css]
[JS|inline|runlast|module=wysiwyg:froala/plugins/line_breaker.min.js]
[JS|inline|runlast|module=wysiwyg:froala/plugins/url.min.js]
[JS|inline|runlast|module=wysiwyg:froala/js/froala-quanta.js]
[CSS|runlast|module=wysiwyg:css/wysiwyg.css]
[CSS|external:https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css]